/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_o_add1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:05:57 by nsheev            #+#    #+#             */
/*   Updated: 2019/11/08 20:07:54 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_hex_o_h(unsigned short a, unsigned base)
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
		print_hex_o_h(a / base, base);
	write(1, &s[a % base], 1);
	free(s);
}

void		len_print_hex_o_h(unsigned short a, unsigned base, int *k)
{
	if (a > base - 1)
		len_print_hex(a / base, base, k);
	(*k)++;
}

void		print_hex_o_hh(unsigned char a, unsigned base)
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
		print_hex_o_hh(a / base, base);
	write(1, &s[a % base], 1);
	free(s);
}

void		len_print_hex_o_hh(unsigned char a, unsigned base, int *k)
{
	if (a > base - 1)
		len_print_hex_o_hh(a / base, base, k);
	(*k)++;
}
