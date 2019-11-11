/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_o_flag_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:37:17 by swedde            #+#    #+#             */
/*   Updated: 2019/11/11 19:26:50 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		strt_min(t_flags *l, unsigned long long a, t_o_struc z, int *i)
{
	if (z.g)
	{
		write(1, "0", 1);
		z.len--;
		(*i)++;
		l->width--;
	}
	while (z.len > z.k)
	{
		write(1, "0", 1);
		(*i)++;
		z.len--;
		l->width--;
	}
}

static void		if_min_o(t_flags *l, unsigned long long a, t_o_struc z, int *i)
{
	strt_min(l, a, z, i);
	if (!z.g && a == 0 && l->precision == 0)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	else
	{
		print_hex_ll_o(a, 8);
		(*i) = (*i) + z.k;
		l->width = l->width - z.k;
	}
	while (l->width > 0)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
}

static void		if_zer_o(t_flags *l, unsigned long long a, t_o_struc z, int *i)
{
	if (z.g)
	{
		write(1, "0", 1);
		(*i)++;
		l->width--;
	}
	while (l->width > z.k)
	{
		write(1, "0", 1);
		(*i)++;
		l->width--;
	}
	print_hex_ll_o(a, 8);
	(*i) = (*i) + z.k;
}

static void		if_els_o(t_flags *l, unsigned long long a, t_o_struc z, int *i)
{
	while (l->width > z.len)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	if (z.g)
	{
		write(1, "0", 1);
		z.len--;
		(*i)++;
		l->width--;
	}
	while (z.len > z.k)
	{
		write(1, "0", 1);
		(*i)++;
		z.len--;
	}
	print_hex_ll_o(a, 8);
	(*i) = (*i) + z.k;
}

int				sw_o_flag_ll(unsigned long long a, t_flags *l)
{
	int			i;
	t_o_struc	z;

	if (a == 0)
		return (sw_ifzero_o(l));
	sw_set_param_o_cas(l, a, &z);
	i = 0;
	if (l->minus)
		if_min_o(l, a, z, &i);
	else if (l->zero)
		if_zer_o(l, a, z, &i);
	else
		if_els_o(l, a, z, &i);
	return (i);
}
