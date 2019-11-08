/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_o_flag_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:37:17 by swedde            #+#    #+#             */
/*   Updated: 2019/11/08 20:43:56 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		sw_o_min(t_flags *l, unsigned long long a, int *i, t_ofl str)
{
	if (str.g)
	{
		write(1, "0", 1);
		str.len--;
		(*i)++;
		l->width--;
	}
	while (str.len > str.k)
	{
		write(1, "0", 1);
		(*i)++;
		str.len--;
		l->width--;
	}
	print_hex_o_ll(a, 8);
	(*i) = (*i) + str.k;
	l->width = l->width - str.k;
	while (l->width > 0)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	return (*i);
}

static int		sw_o_zer(t_flags *l, unsigned long long a, int *i, t_ofl str)
{
	if (str.g)
	{
		write(1, "0", 1);
		(*i)++;
		l->width--;
	}
	while (l->width > str.k)
	{
		write(1, "0", 1);
		(*i)++;
		l->width--;
	}
	print_hex_o_ll(a, 8);
	(*i) = (*i) + str.k;
	return (*i);
}

static int		sw_o_els(t_flags *l, unsigned long long a, int *i, t_ofl str)
{
	while (l->width > str.len)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	if (str.g)
	{
		write(1, "0", 1);
		str.len--;
		(*i)++;
		l->width--;
	}
	while (str.len > str.k)
	{
		write(1, "0", 1);
		(*i)++;
		str.len--;
	}
	print_hex_o_ll(a, 8);
	(*i) = (*i) + str.k;
	return (*i);
}

static t_ofl			sw_set_o_str(unsigned long long a, t_flags *l)
{
	t_ofl		str;

	str.k = 0;
	len_print_hex_o_ll(a, 8, &str.k);
	str.len = str.k;
	if (l->grid && ((l->precision <= str.k && !l->zero) || l->minus))
	{
		str.len++;
		str.g = 1;
	}
	else
	{
		str.g = 0;
	}
	if (str.len < l->precision)
		str.len = l->precision;
	return (str);
}

int				sw_o_flag_ll(unsigned long long a, t_flags *l)
{
	int		i;
	t_ofl	str;

	if (a == 0)
		return (sw_ifzero_o(l));
	str = sw_set_o_str(a, l);
	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (a == 0)
		l->grid = 0;
	i = 0;
	if (l->minus)
		return (sw_o_min(l, a, &i, str));
	else if (l->zero)
		return (sw_o_zer(l, a, &i, str));
	else
		return (sw_o_els(l, a, &i, str));
}
