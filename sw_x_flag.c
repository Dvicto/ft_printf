/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_x_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:37:09 by swedde            #+#    #+#             */
/*   Updated: 2019/10/28 17:30:09 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sw_x_flag(unsigned a, t_flags *l)
{
	int		k;
	int		len;
	int		i;

	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (a == 0)
		l->grid = 0;
	k = 0;
	len_print_hex(a, 16, &k);
	len = k;
	if (len < l->precision)
		len = l->precision;
	if (l->grid)
		len += 2;
	i = 0;
	if (l->minus)
	{
		if (l->grid)
		{
			write(1, "0x", 2);
			len -= 2;
			i += 2;
			l->width -= 2;
		}
		while (len > k)
		{
			write(1, "0", 1);
			i++;
			len--;
			l->width--;
		}
		print_hex(a, 16);
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
		if (l->grid)
		{
			write(1, "0x", 2);
			len -= 2;
			i += 2;
			l->width -= 2;
		}
		while (l->width > k)
		{
			write(1, "0", 1);
			i++;
			l->width--;
		}
		print_hex(a, 16);
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
		if (l->grid)
		{
			write(1, "0x", 2);
			len -= 2;
			i += 2;
			l->width -= 2;
		}
		while (len > k)
		{
			write(1, "0", 1);
			i++;
			len--;
		}
		print_hex(a, 16);
		i = i + k;
	}
	return (i);
}
