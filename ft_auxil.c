/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 05:36:47 by adaifi            #+#    #+#             */
/*   Updated: 2021/12/04 21:19:50 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	data(char c, int *printcount)
{
	*printcount += write(1, &c, 1);
}

void	printadd(unsigned long nb, int *printcount)
{
	char	*add;

	add = "0123456789abcdef";
	if (nb >= 16)
	{
		printadd(nb / 16, printcount);
		printadd(nb % 16, printcount);
	}
	else
		data(add[nb], printcount);
}

void	printhexa(unsigned int nb, int val, unsigned int base, int *printcount)
{
	if (nb >= base)
		printhexa(nb / base, val, base, printcount);
	if (val == 1)
		*printcount += write(1, &"0123456789ABCDEF"[nb % base], 1);
	else if (val == 0)
		*printcount += write(1, &"0123456789abcdef"[nb % base], 1);
}

void	printnbr(int nb, int base, int *printcount)
{
	if (nb == -2147483648)
	{
		*printcount += write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		*printcount += write(1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
		data(nb + 48, printcount);
	else if (nb >= base)
	{
		printnbr(nb / base, base, printcount);
		data((nb % 10) + 48, printcount);
	}
}

void	printunsigned(unsigned int nb, int *printcount)
{
	if (nb >= 10)
	{
		printunsigned(nb / 10, printcount);
		printunsigned(nb % 10, printcount);
	}
	else
		data(nb + 48, printcount);
}
