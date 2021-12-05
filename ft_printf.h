/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 05:28:46 by adaifi            #+#    #+#             */
/*   Updated: 2021/12/05 22:23:37 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(char *s, int *printcount);
size_t	ft_strlen(const char	*str);
void	printadd(unsigned long nb, int *printcount);
void	printnbr(int nb, int base, int *printcount);
void	printunsigned(unsigned int nb, int *printcount);
void	spacenbr(const char *format, va_list arg, int *printcount);
int		ft_atoi(const char *str);
int		lenint(int n);
void	data(char c, int *printcount);
void	printflag(const char *str, va_list arg, int	*printcount);
void	spacemaker(const char *str, va_list arg, int *printcount);
void	printhexa(unsigned int nb, int val, unsigned int base, int *printcount);
void	convert(const char *str, va_list arg, int	*printcount);
void	printsharp(const char *str, va_list arg, int	*printcount);
void	convert_bonus(const char *str, va_list arg, int	*printcount);
void	printre(const char *str, int *i, va_list arg, int	*printcount);
#endif
