/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_x_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:37:09 by swedde            #+#    #+#             */
/*   Updated: 2019/11/08 19:25:33 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sw_x_grid(t_flags *l, int *len, int *i)
{
	write(1, "0x", 2);
	(*len) -= 2;
	(*i) += 2;
	l->width -= 2;
}

static int	sw_x_min(t_flags *l, int len, int *i, unsigned a)
{
	int k;

	k = 0;
	len_print_hex_x_ll(a, 16, &k);
	if (l->grid)
		sw_x_grid(l, &len, i);
	while (len > k)
	{
		write(1, "0", 1);
		(*i)++;
		len--;
		l->width--;
	}
	print_hex_x_ll(a, 16);
	(*i) = (*i) + k;
	l->width = l->width - k;
	while (l->width > 0)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	return (*i);
}

static int	sw_x_zer(t_flags *l, int len, int *i, unsigned a)
{
	int k;

	k = 0;
	len_print_hex_x_ll(a, 16, &k);
	if (l->grid)
		sw_x_grid(l, &len, i);
	while (l->width > k)
	{
		write(1, "0", 1);
		(*i)++;
		l->width--;
	}
	print_hex_x_ll(a, 16);
	(*i) = (*i) + k;
	return (*i);
}

static int	sw_x_els(t_flags *l, int len, int *i, unsigned a)
{
	int k;

	k = 0;
	len_print_hex_x_ll(a, 16, &k);
	while (l->width > len)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	if (l->grid)
		sw_x_grid(l, &len, i);
	while (len > k)
	{
		write(1, "0", 1);
		(*i)++;
		len--;
	}
	print_hex_x_ll(a, 16);
	(*i) = (*i) + k;
	return (*i);
}

int			sw_x_flag(unsigned a, t_flags *l)
{
	int		k;
	int		len;
	int		i;

	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (a == 0)
		return (sw_0if_zero(l));
	k = 0;
	len_print_hex_x_ll(a, 16, &k);
	len = k;
	if (len < l->precision)
		len = l->precision;
	if (l->grid)
		len += 2;
	i = 0;
	if (l->minus)
		return (sw_x_min(l, len, &i, a));
	else if (l->zero)
		return (sw_x_zer(l, len, &i, a));
	else
		return (sw_x_els(l, len, &i, a));
}
