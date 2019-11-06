/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_i_flag_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:24:25 by swedde            #+#    #+#             */
/*   Updated: 2019/11/06 17:27:17 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sw_ft_putnbr_l(long nb)
{
	if (nb == LONG_MIN)
	{
		write(1, "9223372036854775808", 19);
		return ;
	}
	if (nb < 0)
		nb = nb * (-1);
	if (nb / 10)
		sw_ft_putnbr_l(nb / 10);
	ft_putchar(nb % 10 + 48);
}

static int	sw_length(long a)
{
	int i;

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

static void	sw_check_sign_1(int *len, int *i, t_flags *l, long a)
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

static int	sw_if_minus(int *len, t_flags *l, long a)
{
	int		i;

	i = 0;
	sw_check_sign_1(len, &i, l, a);
	while (l->precision > sw_length(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
		l->width--;
	}
	sw_ft_putnbr_l(a);
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

static int	sw_if_zero(int *len, t_flags *l, long a)
{
	int		i;

	i = 0;
	sw_check_sign_1(len, &i, l, a);
	while (l->width > *len)
	{
		write(1, "0", 1);
		i++;
		l->width--;
	}
	sw_ft_putnbr_l(a);
	i += sw_length(a);
	return (i);
}

static int	sw_if_else(int *len, t_flags *l, long a)
{
	int		i;

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
	sw_ft_putnbr_l(a);
	i += sw_length(a);
	return (i);
}

int			sw_i_flag_l(long a, t_flags *l)
{
	int		len;

	len = sw_length(a);
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
		return (sw_if_minus(&len, l, a));
	else if (l->zero)
		return (sw_if_zero(&len, l, a));
	else
		return (sw_if_else(&len, l, a));		
}
