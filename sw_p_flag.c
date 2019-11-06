/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_p_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:17:11 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/06 19:15:19 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

union u_double
{
	void	*p;
	int64_t	byte;
};

static unsigned long	sw_degree_1(unsigned long base, int i)
{
	unsigned long sw;

	sw = 1;
	while (i)
	{
		sw = sw * base;
		i--;
	}
	return (sw);
}

void	long_print_hex_len(long int a, int base, int *k)
{
	if (a > base - 1)
		long_print_hex_len(a / base, base, k);
	(*k)++;
}

void	long_print_hex(unsigned long a, int base)
{
	char s[17] = "0123456789abcdef";
	if (a > base - 1)
		long_print_hex(a / base, base);
	write(1, &s[a % base], 1);
}

int		if_p_null(t_flags *l)
{
	int n;
	int i;

	i = 0;
	if (l->precision == 0)
		n = 2;
	else
		n = 3;
	if (l->minus)
	{
		write(1, "0x0", n);
		i = n;
		while (l->precision - 1> 0)
		{
			write(1, "0", 1);
			i++;
			l->precision--;
		}
		while (l->width - n > 0)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
	}
	else
	{
		while (l->width - n > 0)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
		write(1, "0x0", n);
		i += n;
		while (l->precision - 1 > 0)
		{
			write(1, "0", 1);
			i++;
			l->precision--;
		}
	}
	return (i);
}

int		sw_p_flag(void *a, t_flags *l)
{
	union	u_double	z;
	unsigned long		num;
	int					sw;
	int					len;
	int					i;
	int					k;

	sw = 63;
	i = 0;
	num = 0;
	z.p = a;
	while (sw > -1)
	{
		if (z.byte >> sw & 1)
			num = num + sw_degree_1(2, sw);
		sw--;
	}
	k = 0;
	long_print_hex_len(num, 16, &k);
	len = k + 2;
	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (l->precision > k)
		len = l->precision + 2;
	if (l->plus || l->space)
		len++;
	if (l->zero && l->width > len)
		len = l->width;
	if (a == NULL)
		return(if_p_null(l));
	while (l->width > len && !l->minus)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	if (l->plus)
	{
		write(1, "+", 1);
		i++;
		len--;
		l->width--;
	}
	if (l->space && !l->plus)
	{
		write(1, " ", 1);
		i++;
		len--;
		l->width--;
	}
	write(1, "0x", 2);
	i += 2;
	len -= 2;
	l->width -= 2;
	while (l->zero && l->width > k)
	{
		write(1, "0", 1);
		i++;
		len--;
		l->width--;
	}
	while (l->precision > k)
	{
		write(1, "0", 1);
		i++;
		len--;
		l->precision--;
		l->width--;
	}
	long_print_hex(num, 16);
	i += k;
	l->width -= k;
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}
