/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_x_big_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:31:59 by nsheev            #+#    #+#             */
/*   Updated: 2019/11/08 18:32:41 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		len_print_hex_x_big_ll(unsigned long long a, unsigned base, int *k)
{
	if (a > base - 1)
		len_print_hex_x_big_ll(a / base, base, k);
	(*k)++;
}

void		print_hex_x_big_ll(unsigned long long a, unsigned base)
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
		s[i] = i % 10 + 'A';
		i++;
	}
	if (a > base - 1)
		print_hex_x_big_ll(a / base, base);
	write(1, &s[a % base], 1);
	free(s);
}
