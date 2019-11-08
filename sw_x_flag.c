/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_x_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:37:09 by swedde            #+#    #+#             */
/*   Updated: 2019/11/08 17:35:05 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	len_print_hex_x(unsigned a, unsigned base, int *k)
{
	if (a > base - 1)
		len_print_hex_x(a / base, base, k);
	(*k)++;
}

void	print_hex_x(unsigned a, unsigned base)
{
	char	*s;
	int		i;

	s = (char*)malloc(sizeof(char) * 17);
	s[16] = '\0';
	i = 0;
	while (i < 10)
	{
		s[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		s[i] = i % 10 + 'a';
		i++;
	}
	if (a > base - 1)
		print_hex_x(a / base, base);
	write(1, &s[a % base], 1);
	free(s);
}

int		sw_x_flag(unsigned a, t_flags *l)
{
	int		k;
	int		len;
	int		i;

	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (a == 0)
		return(sw_0if_zero(l));
	k = 0;
	len_print_hex_x(a, 16, &k);
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
		print_hex_x(a, 16);
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
		print_hex_x(a, 16);
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
		print_hex_x(a, 16);
		i = i + k;
	}
	return (i);
}
