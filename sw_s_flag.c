/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:57:27 by nsheev            #+#    #+#             */
/*   Updated: 2019/10/30 16:34:42 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sw_s_flag(char *s, t_flags *l)
{
	int		i;
	int		len;

	i = 0;
	if (s)
		len = ft_strlen(s);
	else
		len = 0;
	if (l->precision != -1 && len > l->precision)
		len = l->precision;
	if (l->minus == 0)
		while (l->width > len)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
	write(1, s, len);
	i += len;
	l->width -= len;
	while (l->width > 0)
	{
		write(1, " ", 1);
		l->width--;
		i++;
	}
	return (i);
}
