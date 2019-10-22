/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swedde <swedde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:57:27 by nsheev            #+#    #+#             */
/*   Updated: 2019/10/21 20:10:38 by swedde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

int		sw_s_flag(char *s, t_flags *l)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
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
