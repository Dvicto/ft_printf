/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_if_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swedde <swedde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 00:30:44 by swedde            #+#    #+#             */
/*   Updated: 2019/10/30 00:34:47 by swedde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sw_if_zero(t_flags *l)
{
	int len;
	int i;

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
			l->width--;
		}
		else if (l->space)
		{
			write(1, " ", 1);
			l->width--;
		}
		while (l->precision > 0)
		{
			write(1, "0", 1);
			l->width--;
			l->precision--;
		}
		while (l->width > 0)
		{
			write(1, " ", 1);
			l->width--;
		}
	}
	else if (l->zero)
	{
		if (l->plus)
		{
			write(1, "+", 1);
			l->width--;
		}
		else if (l->space)
		{
			write(1, " ", 1);
			l->width--;
		}
		if (l->width <= 0)
			write(1, "0", 1);
		while (l->width > 0)
		{
			write(1, "0", 1);
			l->width--;
		}
	}
	else
	{
		while (l->width > len)
		{
			write(1, " ", 1);
			l->width--;
		}
		if (l->plus)
			write(1, "+", 1);
		else if (l->space)
			write(1, " ", 1);
		if (l->precision == -1)
			write(1, "0", 1);
		while (l->precision > 0)
		{
			write(1, "0", 1);
			l->precision--;
		}
	}
}