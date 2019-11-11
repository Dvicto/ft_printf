/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_o_addion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:12:39 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/11 19:26:57 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		len_print_hex_ll_o_o(unsigned long long a, unsigned base, int *k)
{
	if (a > base - 1)
		len_print_hex_ll_o_o(a / base, base, k);
	(*k)++;
}

void		print_hex_ll_o(unsigned long long a, unsigned base)
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
		print_hex_ll_o(a / base, base);
	write(1, &s[a % base], 1);
	free(s);
}

void		sw_set_param_o_cas(t_flags *l, unsigned long long a, t_o_struc *z)
{
	(*z).g = 0;
	if (l->precision > -1 || l->minus)
		l->zero = 0;
	(*z).k = 0;
	len_print_hex_ll_o_o(a, 8, &((*z).k));
	(*z).len = (*z).k;
	if ((*z).len < l->precision)
		(*z).len = l->precision;
	if (l->grid && ((l->precision <= (*z).k && !l->zero) || l->minus))
	{
		(*z).len++;
		(*z).g = 1;
	}
	if ((*z).g && l->minus && l->precision > (*z).k)
	{
		(*z).len--;
		(*z).g--;
	}
	if (l->precision == -1 && l->zero &&
		(*z).k == l->width && l->grid && !(*z).g)
	{
		(*z).len++;
		(*z).g = 1;
	}
}
