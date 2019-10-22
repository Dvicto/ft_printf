/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swedde <swedde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:49:50 by swedde            #+#    #+#             */
/*   Updated: 2019/10/21 21:38:04 by swedde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

void	len_print_hex(unsigned a, unsigned base, int *k)
{
	if (a > base - 1)
		len_print_hex(a / base, base, k);
	(*k)++;
}

void	print_hex(unsigned a, unsigned base)
{
	char s[17] = "0123456789abcdef";
	
	if (a > base - 1)
		print_hex(a / base, base);
	write(1, &s[a % base], 1);
}
