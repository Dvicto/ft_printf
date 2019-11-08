/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:49:50 by swedde            #+#    #+#             */
/*   Updated: 2019/10/28 17:28:50 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	len_print_hex(unsigned a, unsigned base, int *k)
{
	if (a > base - 1)
		len_print_hex(a / base, base, k);
	(*k)++;
}

void	print_hex(unsigned a, unsigned base)
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
		print_hex(a / base, base);
	write(1, &s[a % base], 1);
}

int		sw_degree(int base, int i)
{
	int		sw;

	sw = 1;
	while (i)
	{
		sw = sw * base;
		i--;
	}
	return (sw);
}
