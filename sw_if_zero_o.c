/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_if_zero_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:21:31 by nsheev            #+#    #+#             */
/*   Updated: 2019/11/11 19:41:36 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sw_set_param_o(t_flags *l, t_o_struc *z, int *i)
{
	(*z).g = 0;
	(*z).len = 1;
	if (l->precision > -1)
		(*z).len = l->precision;
	if (l->space)
		(*z).len++;
	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (l->precision == 0 && l->grid == 1)
		(*z).g = 1;
	(*i) = 0;
}

static void	sw_0_o_else(t_flags *l, t_o_struc z, int *i)
{
	while (l->width > z.len + z.g)
	{
		write(1, " ", 1);
		l->width--;
		(*i)++;
	}
	if (l->space)
	{
		write(1, " ", 1);
		l->width--;
		z.len--;
		(*i)++;
	}
	if (z.g)
	{
		write(1, "0", 1);
		l->width--;
		(*i)++;
	}
	while (z.len > 0)
	{
		write(1, "0", 1);
		z.len--;
		(*i)++;
	}
}

static void	sw_0_o_zero(t_flags *l, int *i)
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
}

static void	sw_0_o_min(t_flags *l, t_o_struc z, int *i)
{
	if (l->precision == -1)
	{
		write(1, "0", 1);
		l->width--;
		(*i)++;
	}
	if (z.g)
	{
		write(1, "0", 1);
		l->width--;
		(*i)++;
	}
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
}

int			sw_ifzero_o(t_flags *l)
{
	int			i;
	t_o_struc	z;

	sw_set_param_o(l, &z, &i);
	if (l->minus)
	{
		if (l->space)
		{
			write(1, " ", 1);
			l->width--;
			i++;
		}
		sw_0_o_min(l, z, &i);
	}
	else if (l->zero)
		sw_0_o_zero(l, &i);
	else
		sw_0_o_else(l, z, &i);
	return (i);
}
