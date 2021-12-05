/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:45:26 by adaifi            #+#    #+#             */
/*   Updated: 2021/12/05 23:05:53 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenint(int n)
{
	int	len;

	len = 0;
	if (n < 0 || n == 0)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	convert_bonus(const char *str, va_list arg, int	*printcount)
{
	int		c;

	if (*str == '%')
		*printcount += write(1, "%", 1);
	if (*str == 's')
		ft_putstr(va_arg(arg, char *), printcount);
	else if (*str == 'c')
	{
		c = va_arg(arg, int);
		*printcount += write(1, &c, 1);
	}
	else if (*str == 'd' || *str == 'i')
		printnbr(va_arg(arg, int), 10, printcount);
	else if (*str == 'X')
		printhexa(va_arg(arg, unsigned int), 1, 16, printcount);
	else if (*str == 'x')
		printhexa(va_arg(arg, unsigned int), 0, 16, printcount);
	else if (*str == 'u')
		printunsigned(va_arg(arg, unsigned int), printcount);
	else if (*str == 'p')
	{
		ft_putstr("0x", printcount);
		printadd(va_arg(arg, unsigned long), printcount);
	}
}

void	printsharp(const char *str, va_list arg, int	*printcount)
{
	int					i;
	unsigned int		nb;

	i = 0;
	nb = va_arg(arg, unsigned int);
	if (nb == 0)
		*printcount += write(1, "0", 1);
	else if (str[i + 1] == 'x')
	{
		*printcount += write(1, "0x", 2);
		printhexa(nb, 0, 16, printcount);
	}
	else if (str[i + 1] == 'X')
	{
		*printcount += write(1, "0X", 2);
		printhexa(nb, 1, 16, printcount);
	}
}

void	printre(const char *str, int *i, va_list arg, int	*printcount)
{
	if (str[*i] == '+' || str[*i] == ' ' || str[*i] == '#')
	{
		printflag(&str[*i], arg, printcount);
		if ((str[*i] == '+' || str[*i] == ' ')
			&& (str[*i + 1] >= '0' && str[*i + 1] <= '9'))
			*i += lenint(ft_atoi(&str[*i + 1])) + 1;
		else
			*i += lenint(ft_atoi(&str[*i + 1]));
	}
	else
		convert_bonus(&str[*i], arg, printcount);
}
