/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_i_flag_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:24:25 by swedde            #+#    #+#             */
/*   Updated: 2019/11/08 18:07:51 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			sw_check_sign_1_h(int *len, int *i, t_flags *l, short a)
{
	if (a < 0)
	{
		write(1, "-", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
	if (l->plus && a > -1)
	{
		write(1, "+", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
	if (l->space && !l->plus && a > -1)
	{
		write(1, " ", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
}

static int			sw_if_minus_h(int *len, t_flags *l, short a)
{
	int				i;

	i = 0;
	sw_check_sign_1_h(len, &i, l, a);
	while (l->precision > sw_length_h(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
		l->width--;
	}
	sw_ft_putnbr_i_h(a);
	i += sw_length_h(a);
	l->width -= sw_length_h(a);
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}

static int			sw_if_zero_h(int *len, t_flags *l, short a)
{
	int				i;

	i = 0;
	sw_check_sign_1_h(len, &i, l, a);
	while (l->width > *len)
	{
		write(1, "0", 1);
		i++;
		l->width--;
	}
	sw_ft_putnbr_i_h(a);
	i += sw_length_h(a);
	return (i);
}

static int			sw_if_else_h(int *len, t_flags *l, short a)
{
	int				i;

	i = 0;
	while (l->width > *len)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	if (l->precision != -1 && l->width > l->precision && a == 0)
	{
		write(1, " ", 1);
	}
	sw_check_sign_1_h(len, &i, l, a);
	while (l->precision > sw_length_h(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
	}
	sw_ft_putnbr_i_h(a);
	i += sw_length_h(a);
	return (i);
}

int					sw_i_flag_h(short a, t_flags *l)
{
	int				len;

	len = sw_length_h(a);
	if (a == 0)
	{
		return (sw_0if_zero(l));
	}
	if (l->minus || l->precision > -1)
		l->zero = 0;
	if (l->precision > len)
		len = l->precision;
	if (a < 0 || l->plus || l->space)
		len++;
	if (l->minus)
		return (sw_if_minus_h(&len, l, a));
	else if (l->zero)
		return (sw_if_zero_h(&len, l, a));
	else
		return (sw_if_else_h(&len, l, a));
}