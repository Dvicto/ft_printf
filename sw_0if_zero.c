/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_0if_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 00:30:44 by swedde            #+#    #+#             */
/*   Updated: 2019/11/06 15:23:24 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sw_0if_zero(t_flags *l)
{
	int len;
	int i;

	i = 0;
	len = 1;
	if (l->precision > -1)
	{
		l->zero = 0;
		len = l->precision;
	}
	if (l->space || l->plus)
		len++;
	if (l->minus)
	{
		if (l->plus)
		{
			write(1, "+", 1);
			i++;
			l->width--;
		}
		else if (l->space)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
		if (l->precision == -1)
		{
			write(1, "0", 1);
			i++;
			l->width--;
		}
		while (l->precision > 0)
		{
			write(1, "0", 1);
			i++;
			l->width--;
			l->precision--;
		}
		while (l->width > 0)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
	}
	else if (l->zero)
	{
		if (l->plus)
		{
			write(1, "+", 1);
			i++;
			l->width--;
		}
		else if (l->space)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
		if (l->width <= 0)
		{
			write(1, "0", 1);
			i++;
		}
		while (l->width > 0)
		{
			write(1, "0", 1);
			i++;
			l->width--;
		}
	}
	else
	{
		while (l->width > len)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
		if (l->plus)
		{
			write(1, "+", 1);
			i++;
		}
		else if (l->space)
		{
			write(1, " ", 1);
			i++;
		}
		if (l->precision == -1)
		{
			write(1, "0", 1);
			i++;
		}
		while (l->precision > 0)
		{
			write(1, "0", 1);
			i++;
			l->precision--;
		}
	}
	return (i);
}
