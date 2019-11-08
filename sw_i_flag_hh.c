/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_i_flag_hh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:24:25 by swedde            #+#    #+#             */
/*   Updated: 2019/11/08 16:40:14 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			sw_ft_putnbr_i_hh(char nb)
{
	if (nb == -128)
	{
		write(1, "128", 3);
		return ;
	}
	if (nb < 0)
		nb = nb * (-1);
	if (nb / 10)
		sw_ft_putnbr_i_hh(nb / 10);
	ft_putchar(nb % 10 + 48);
}

static int			sw_length_hh(char a)
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

static void			sw_check_sign_1hh(int *len, int *i, t_flags *l, char a)
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

static int			sw_if_minus_hh(int *len, t_flags *l, char a)
{
	int				i;

	i = 0;
	sw_check_sign_1hh(len, &i, l, a);
	while (l->precision > sw_length_hh(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
		l->width--;
	}
	sw_ft_putnbr_i_hh(a);
	i += sw_length_hh(a);
	l->width -= sw_length_hh(a);
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}

static int			sw_if_zero_hh(int *len, t_flags *l, char a)
{
	int				i;

	i = 0;
	sw_check_sign_1hh(len, &i, l, a);
	while (l->width > *len)
	{
		write(1, "0", 1);
		i++;
		l->width--;
	}
	sw_ft_putnbr_i_hh(a);
	i += sw_length_hh(a);
	return (i);
}

static int			sw_if_else_hh(int *len, t_flags *l, char a)
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
	sw_check_sign_1hh(len, &i, l, a);
	while (l->precision > sw_length_hh(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
	}
	sw_ft_putnbr_i_hh(a);
	i += sw_length_hh(a);
	return (i);
}
