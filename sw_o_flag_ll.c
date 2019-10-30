/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_o_flag_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:37:17 by swedde            #+#    #+#             */
/*   Updated: 2019/10/30 16:25:15 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sw_o_flag_ll(unsigned long long a, t_flags *l)
{
	int		k;
	int		len;
	int		i;
	int		g;

	g = 0;
	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (a == 0)
		l->grid = 0;
	k = 0;
	len_print_hex(a, 8, &k);
	len = k;
	if (len < l->precision)
		len = l->precision;
	if (l->grid && ((l->precision <= k && !l->zero) || l->minus))
	{
		len++;
		g = 1;
	}
	i = 0;
	if (l->minus)
	{
		if (g)
		{
			write(1, "0", 1);
			len--;
			i++;
			l->width--;
		}
		while (len > k)
		{
			write(1, "0", 1);
			i++;
			len--;
			l->width--;
		}
		print_hex(a, 8);
		i = i + k;
		l->width = l->width - k;
		while (l->width > 0)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
	}
	else if (l->zero)
	{
		if (g)
		{
			write(1, "0", 1);
			i++;
			l->width--;
		}
		while (l->width > k)
		{
			write(1, "0", 1);
			i++;
			l->width--;
		}
		print_hex(a, 8);
		i = i + k;
	}
	else
	{
		while (l->width > len)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
		if (g)
		{
			write(1, "0", 1);
			len--;
			i++;
			l->width--;
		}
		while (len > k)
		{
			write(1, "0", 1);
			i++;
			len--;
		}
		print_hex(a, 8);
		i = i + k;
	}
	return (i);
}
