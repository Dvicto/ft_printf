/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_if0_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:31:26 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/08 20:47:13 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	o_write(t_flags *l, int *i, int g)
{
	if (l->space)
	{
		write(1, " ", 1);
		l->width--;
		(*i)++;
	}
	if (l->precision == -1)
	{
		write(1, "0", 1);
		l->width--;
		(*i)++;
	}
	if (g)
	{
		write(1, "0", 1);
		l->width--;
		(*i)++;
	}
}

static int	sw_if_minus(t_flags *l, int *i, int g)
{
	o_write(l, i, g);
	while (l->precision > 0)
	{
		write(1, "0", 1);
		l->precision--;
		l->width--;
		(*i)++;
	}
	while (l->width > 0)
	{
		write(1, " ", 1);
		l->width--;
		(*i)++;
	}
	return (*i);
}

static int sw_if_zero(t_flags *l, int *i)
{
	if (l->space)
	{
		write(1, " ", 1);
		l->width--;
		(*i)++;
	}
	while (l->width > 0)
	{
		write(1, "0", 1);
		l->width--;
		(*i)++;
	}
	return (*i);
}

static int sw_if_else(t_flags *l, int *i, int len, int g)
{
	while (l->width > len + g)
	{
		write(1, " ", 1);
		l->width--;
		(*i)++;
	}
	if (l->space)
	{
		write(1, " ", 1);
		l->width--;
		len--;
		(*i)++;
	}
	if (g)
	{
		write(1, "0", 1);
		l->width--;
		(*i)++;
	}
	while (len > 0)
	{
		write(1, "0", 1);
		len--;
		(*i)++;
	}
	return (*i);
}

int		sw_ifzero_o(t_flags *l)
{
	int i;
	int len;
	int g;

	g = 0;
	i = 0;
	len = 1;
	if (l->precision > -1)
		len = l->precision;
	if (l->space)
		len++;
	if (l->precision > -1)
		l->zero = 0;
	if (l->precision == 0 && l->grid == 1)
		g = 1;
	if (l->minus)
		return (sw_if_minus(l, &i, g));
	else if (l->zero)
		return (sw_if_zero(l, &i));
	else
		return (sw_if_else(l, &i, len, g));
}
