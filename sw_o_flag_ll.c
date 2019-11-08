/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_o_flag_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:37:17 by swedde            #+#    #+#             */
/*   Updated: 2019/11/08 15:35:20 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	len_print_hex_ll(unsigned long long a, unsigned base, int *k)
{
	if (a > base - 1)
		len_print_hex_ll(a / base, base, k);
	(*k)++;
}

static void	print_hex_ll(unsigned long long a, unsigned base)
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
		print_hex_ll(a / base, base);
	write(1, &s[a % base], 1);
	free(s);
}

static int sw_ifzero_o(t_flags *l)
{
	int i;
	int len;
	int g;

	g = 0;
	i = 0;
	len = 1;
	if (l->precision > -1)
		len = l->precision;
	if (l->space)
		len++;
	if (l->precision > -1)
		l->zero = 0;
	if (l->precision == 0 && l->grid == 1)
		g = 1;
	if (l->minus)
	{
		l->zero = 0;
		if (l->space)
		{
			write(1, " ", 1);
			l->width--;
			i++;
		}
		if (l->precision == -1)
		{
			write(1, "0", 1);
			l->width--;
			i++;
		}
		if (g)
		{
			write(1, "0", 1);
			l->width--;
			i++;
		}
		while (l->precision > 0)
		{
			write(1, "0", 1);
			l->precision--;
			l->width--;
			i++;
		}
		while (l->width > 0)
		{
			write(1, " ", 1);
			l->width--;
			i++;
		}
	}
	else if (l->zero)
	{
		if (l->space)
		{
			write(1, " ", 1);
			l->width--;
			i++;
		}
		while (l->width > 0)
		{
			write(1, "0", 1);
			l->width--;
			i++;
		}
	}
	else
	{
		while (l->width > len + g)
		{
			write(1, " ", 1);
			l->width--;
			i++;
		}
		if (l->space)
		{
			write(1, " ", 1);
			l->width--;
			len--;
			i++;
		}
		if (g)
		{
			write(1, "0", 1);
			l->width--;
			i++;
		}
		while (len > 0)
		{
			write(1, "0", 1);
			len--;
			i++;
		}
	}
	return (i);
}

int		sw_o_flag_ll(unsigned long long a, t_flags *l)
{
	int		k;
	int		len;
	int		i;
	int		g;
	int		z;

	z = 0;
	g = 0;
	if (a == 0)
		return (sw_ifzero_o(l));
	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (a == 0)
	{
		l->grid = 0;
		if (!l->minus)
			z = 1;
	}
	k = 0;
	len_print_hex_ll(a, 8, &k);
	len = k;
	if (len < l->precision)
		len = l->precision;
	if (l->grid && ((l->precision <= k && !l->zero) || l->minus))
	{
		len++;
		g = 1;
	}
	if (g && l->minus && l->precision > k)
	{
		len--;
		g--;
	}
	if (l->precision == -1 && l->zero && k == l->width && l->grid && !g)
	{
		len++;
		g = 1;
	}
	i = 0;
	if (l->minus)
	{
		if (g || z)
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
		if (!g && a == 0 && l->precision == 0 && z)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
		else
		{
			print_hex_ll(a, 8);
			i = i + k;
			l->width = l->width - k;
		}
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
		print_hex_ll(a, 8);
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
		print_hex_ll(a, 8);
		i = i + k;
	}
	return (i);
}
