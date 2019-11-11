/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_p_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:17:11 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/11 18:48:26 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	sw_p_norm3(int *k, unsigned long *num, int *len, t_flags *l)
{
	(*k) = 0;
	long_print_hex_len(*num, 16, k);
	(*len) = (*k) + 2;
	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (l->precision > (*k))
		(*len) = l->precision + 2;
	if (l->plus || l->space)
		(*len)++;
	if (l->zero && l->width > (*len))
		(*len) = l->width;
}

static	void	sw_p_norm2(int *i, int *len, t_flags *l)
{
	while (l->width > (*len) && !l->minus)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	if (l->plus)
	{
		write(1, "+", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
	if (l->space && !l->plus)
	{
		write(1, " ", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
}

static	void	sw_p_norm1(int *len, int *i, int *k, t_flags *l)
{
	write(1, "0x", 2);
	(*i) += 2;
	(*len) -= 2;
	l->width -= 2;
	while (l->zero && l->width > (*k))
	{
		write(1, "0", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
	while (l->precision > (*k))
	{
		write(1, "0", 1);
		(*i)++;
		(*len)--;
		l->precision--;
		l->width--;
	}
}

static	void	sw_p_norm4(int *i, int *k, t_flags *l)
{
	(*i) += (*k);
	l->width -= (*k);
	while (l->width > 0)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
}

int				sw_p_flag(void *a, t_flags *l, int len, int i)
{
	union u_double		z;
	unsigned long		num;
	int					sw;
	int					k;

	sw = 63;
	i = 0;
	num = 0;
	z.p = a;
	while (sw > -1)
	{
		if (z.byte >> sw & 1)
			num = num + sw_degree_1(2, sw);
		sw--;
	}
	sw_p_norm3(&k, &num, &len, l);
	if (a == NULL)
		return (if_p_null(l));
	sw_p_norm2(&i, &len, l);
	sw_p_norm1(&len, &i, &k, l);
	long_print_hex(num, 16);
	sw_p_norm4(&i, &k, l);
	return (i);
}
