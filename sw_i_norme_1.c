/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_i_norme_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:40:40 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/08 16:42:45 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int					sw_i_flag_l(long a, t_flags *l)
{
	int				len;

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

int					sw_i_flag_ll(long long a, t_flags *l)
{
	int				len;

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

int					sw_i_flag_hh(char a, t_flags *l)
{
	int				len;

	len = sw_length_hh(a);
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
		return (sw_if_minus_hh(&len, l, a));
	else if (l->zero)
		return (sw_if_zero_hh(&len, l, a));
	else
		return (sw_if_else_hh(&len, l, a));
}

int					sw_i_flag(int a, t_flags *l)
{
	int				len;

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
