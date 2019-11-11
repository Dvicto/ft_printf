/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_p_flag_norme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:17:11 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/11 18:47:25 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	sw_degree_1(unsigned long base, int i)
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

void			long_print_hex_len(unsigned long int a,
	unsigned long base, int *k)
{
	if (a > base - 1)
		long_print_hex_len(a / base, base, k);
	(*k)++;
}

void			long_print_hex(unsigned long a, unsigned long base)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * 17);
	while (i < 10)
	{
		s[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		s[i] = i + 87;
		i++;
	}
	s[i] = '\0';
	if (a > base - 1)
		long_print_hex(a / base, base);
	write(1, &s[a % base], 1);
	free(s);
}
