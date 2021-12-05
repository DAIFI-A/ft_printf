/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 05:26:48 by adaifi            #+#    #+#             */
/*   Updated: 2021/11/28 22:49:20 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *printcount)
{
	if (s == NULL)
	{
		*printcount += write(1, "(null)", 6);
		return ;
	}
	while (*s)
	{
		*printcount += write(1, s, 1);
		s++;
	}
}
