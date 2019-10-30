/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:57:27 by nsheev            #+#    #+#             */
/*   Updated: 2019/10/30 17:34:43 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*set_null(void)
{
	char *s;

	s = (char*)malloc(sizeof(char) * 7);
	s[6] = '\0';
	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	return (s);
}

static int s_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		sw_s_flag(char *s, t_flags *l)
{
	int		i;
	int		len;

	i = 0;
	if (!s)
		s = set_null();
	len = s_strlen(s);
	if (l->precision != -1 && len > l->precision)
		len = l->precision;
	if (l->minus == 0)
		while (l->width > len)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
	if (s[0] != '\0')
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
