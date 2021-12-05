/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 04:37:07 by adaifi            #+#    #+#             */
/*   Updated: 2021/12/05 23:08:50 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(const char *str, va_list arg, int	*printcount)
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
	else if (*str == 'x')
		printhexa(va_arg(arg, unsigned int), 0, 16, printcount);
	else if (*str == 'X')
		printhexa(va_arg(arg, unsigned int), 1, 16, printcount);
	else if (*str == 'u')
		printunsigned(va_arg(arg, unsigned int), printcount);
	else if (*str == 'p')
	{
		ft_putstr("0x", printcount);
		printadd(va_arg(arg, unsigned long), printcount);
	}
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				j;
	va_list			arg;

	va_start(arg, format);
	i = 0;
	j = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			convert(&format[i + 1], arg, &j);
			i++;
		}
		else
			j += write(1, &format[i], 1);
		i++;
	}
	return (j);
}
// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
// 	int p = ft_printf("%c", 'c');
// 	printf("%d", p);
// 	return 0;
// }
