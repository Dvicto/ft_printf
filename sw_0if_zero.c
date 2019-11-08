/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_0if_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 00:30:44 by swedde            #+#    #+#             */
/*   Updated: 2019/11/08 17:24:50 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sw_0ch_sig(t_flags *l, int *i)
{
	if (l->plus)
	{
		write(1, "+", 1);
		(*i)++;
		l->width--;
	}
	else if (l->space)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
}

static int	sw_0minus(t_flags *l, int *i)
{
	sw_0ch_sig(l, i);
	if (l->precision == -1)
	{
		write(1, "0", 1);
		(*i)++;
		l->width--;
	}
	while (l->precision > 0)
	{
		write(1, "0", 1);
		(*i)++;
		l->width--;
		l->precision--;
	}
	while (l->width > 0)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	return (*i);
}

static int	sw_0zero(t_flags *l, int *i)
{
	if (l->plus)
	{
		write(1, "+", 1);
		(*i)++;
		l->width--;
	}
	else if (l->space)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	if (l->width <= 0)
	{
		write(1, "0", 1);
		(*i)++;
	}
	while (l->width > 0)
	{
		write(1, "0", 1);
		(*i)++;
		l->width--;
	}
	return (*i);
}

static int	sw_0else(t_flags *l, int len, int *i)
{
	while (l->width > len)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	sw_0ch_sig(l, i);
	if (l->precision == -1)
	{
		write(1, "0", 1);
		(*i)++;
	}
	while (l->precision > 0)
	{
		write(1, "0", 1);
		(*i)++;
		l->precision--;
	}
	return (*i);
}

int			sw_0if_zero(t_flags *l)
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
		return (sw_0minus(l, &i));
	else if (l->zero)
		return (sw_0zero(l, &i));
	else
		return (sw_0else(l, len, &i));
}
