/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_u_flag_hh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:24:25 by swedde            #+#    #+#             */
/*   Updated: 2019/11/06 17:35:22 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		sw_ft_putnbr_u_cas(unsigned char nb)
{
	if (nb / 10)
		sw_ft_putnbr_u_cas(nb / 10);
	ft_putchar(nb % 10 + 48);
}

static int			sw_length_u_cas(unsigned char a)
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

static void	sw_check_sign_1(int *len, int *i, t_flags *l, unsigned char a)
{
	if (l->space)
	{
		write(1, " ", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
}

static int	sw_if_minus(int *len, t_flags *l, unsigned char a)
{
	int		i;

	i = 0;
	sw_check_sign_1(len, &i, l, a);
	while (l->precision > sw_length_u_cas(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
		l->width--;
	}
	sw_ft_putnbr_u_cas(a);
	i += sw_length_u_cas(a);
	l->width -= sw_length_u_cas(a);
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}

static int	sw_if_zero(int *len, t_flags *l, unsigned char a)
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
	sw_ft_putnbr_u_cas(a);
	i += sw_length_u_cas(a);
	return (i);
}

static int	sw_if_else(int *len, t_flags *l, unsigned char a)
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
	while (l->precision > sw_length_u_cas(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
	}
	sw_ft_putnbr_u_cas(a);
	i += sw_length_u_cas(a);
	return (i);
}

int			sw_u_flag_hh(unsigned char a, t_flags *l)
{
	int		len;

	len = sw_length_u_cas(a);
	if (a == 0)
	{
		return (sw_0if_zero(l));
	}
	if (l->minus || l->precision > -1)
		l->zero = 0;
	if (l->precision > len)
		len = l->precision;
	if (l->space)
		len++;
	if (l->minus)
		return (sw_if_minus(&len, l, a));
	else if (l->zero)
		return (sw_if_zero(&len, l, a));
	else
		return (sw_if_else(&len, l, a));		
}
