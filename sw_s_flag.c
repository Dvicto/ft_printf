/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:57:27 by nsheev            #+#    #+#             */
/*   Updated: 2019/11/08 19:51:13 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*set_null(void)
{
	char		*s;

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

static int		s_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int				sw_s_flag(char *s, t_flags *l, int i, int f)
{
	int			len;

	if (!s)
	{
		s = set_null();
		f = 1;
	}
	len = s_strlen(s);
	(l->precision != -1 && len > l->precision) ? len = l->precision : 1;
	if (l->minus == 0)
		while (l->width-- > len)
		{
			write(1, " ", 1);
			i++;
		}
	s[0] != '\0' ? write(1, s, len) : 1;
	i += len;
	l->width -= len;
	while (l->width-- > 0)
	{
		write(1, " ", 1);
		i++;
	}
	f ? free(s) : 1;
	return (i);
}
