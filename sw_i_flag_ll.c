/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_i_flag_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:24:25 by swedde            #+#    #+#             */
/*   Updated: 2019/11/08 16:40:03 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			sw_ft_putnbr_ll(long long nb)
{
	if (nb == LLONG_MIN)
	{
		write(1, "9223372036854775808", 19);
		return ;
	}
	if (nb < 0)
		nb = nb * (-1);
	if (nb / 10)
		sw_ft_putnbr_ll(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int				sw_length(long long a)
{
	int			i;

	if (!a)
		return (1);
	i = 0;
	while (a)
	{
		i++;
		a /= 10;
	}
	return (i);
}

static void		sw_check_sign_1(int *len, int *i, t_flags *l, long long a)
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

static int		sw_if_minus(int *len, t_flags *l, long long a)
{
	int			i;

	i = 0;
	sw_check_sign_1(len, &i, l, a);
	while (l->precision > sw_length(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
		l->width--;
	}
	sw_ft_putnbr_ll(a);
	i += sw_length(a);
	l->width -= sw_length(a);
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}

static int		sw_if_zero(int *len, t_flags *l, long long a)
{
	int			i;

	i = 0;
	sw_check_sign_1(len, &i, l, a);
	while (l->width > *len)
	{
		write(1, "0", 1);
		i++;
		l->width--;
	}
	sw_ft_putnbr_ll(a);
	i += sw_length(a);
	return (i);
}

static int		sw_if_else(int *len, t_flags *l, long long a)
{
	int			i;

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
	sw_check_sign_1(len, &i, l, a);
	while (l->precision > sw_length(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
	}
	sw_ft_putnbr_ll(a);
	i += sw_length(a);
	return (i);
}
