/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 02:31:21 by adaifi            #+#    #+#             */
/*   Updated: 2021/12/05 23:11:01 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "ft_printf.h"

int	plusflag(const char *str)
{
	int		nb;

	nb = ft_atoi(str);
	return (nb);
}

void	spacemaker(const char *str, va_list arg, int *printcount)
{
	int		nb;
	int		r;
	int		i;
	int		j;

	i = 0;
	j = -1;
	r = 0;
	if (str[i] >= '0' && str[i] <= '9')
		r = ft_atoi(&str[i]);
	nb = va_arg(arg, int);
	r -= lenint(nb);
	if (str[j] == '+')
	{
		while (r-- >= 0)
			data(' ', printcount);
		if (nb >= 0)
			*printcount += write(1, "+", 1);
		printnbr(nb, 10, printcount);
	}
}

void	printflag(const char *str, va_list arg, int	*printcount)
{
	int		i;
	int		n;

	i = 0;
	if ((str[i] == '+') || (str[i] == '-'))
		spacemaker(&str[++i], arg, printcount);
	if (str[i] == ' ')
	{
		if ((str[i + 1] == 'd' || str[i + 1] == 'i'))
		{
			n = va_arg(arg, int);
			if (n >= 0)
				*printcount += write(1, " ", 1);
			printnbr(n, 10, printcount);
		}
		else
		{
			i = ft_atoi(&str[i + 1]);
			while (i-- > 0)
				data(' ', printcount);
			ft_putstr(va_arg(arg, char *), printcount);
		}
	}
	else if (str[i] == '#')
		printsharp(&str[i], arg, printcount);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				j;
	va_list			arg;

	va_start(arg, format);
	i = -1;
	j = 0;
	while (format[++i] != 0)
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
				j += write(1, "%", 1);
			else
				printre(format, &i, arg, &j);
		}
		else
			j += write(1, &format[i], 1);
	}
	return (j);
}
// #include<stdio.h>
// int main(int argc, char const *argv[])
// {
// 	int c = 15;
// 	int ret;
// 	ret = ft_printf("|% 1s|", "");
// 	printf("\n\n%d\n", ret);
// 	ret = printf("|% 1s|", "");
// 	printf("\n\n%d\n", ret);
// 	return 0;
// }
