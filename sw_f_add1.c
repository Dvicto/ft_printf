/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_f_add1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:26:58 by nsheev            #+#    #+#             */
/*   Updated: 2019/10/28 17:28:56 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_byte		set_byte_srtuct(union common z)
{
	t_byte b;

	b.m = 51;
	b.p = 10;
	b.por = 0;
	while (b.p > -1)
	{
		if (z.t_double.p >> b.p & 1)
			b.por = b.por + sw_degree(2, b.p);
		b.p--;
	}
	b.por = b.por - 1023;
	if (b.por > -1)
		b.f = 1;
	else
		b.f = 0;
	return (b);
}

void		sw_increase(char *one)
{
	char *s;

	s = (char*)malloc(sizeof(char) * 349);
	s[348] = '\0';
	memset(s, '0', 348);
	s[347] = '1';
	arif_plus(one, s);
	free(s);
}

char		*set_one(t_byte *b, union common z)
{
	char	*one;
	char	*buf;

	one = (char*)malloc(sizeof(char) * 349);
	one[348] = '\0';
	memset(one, '0', 348);
	if ((*b).f == 1)
	{
		free(one);
		one = arif_degree(2, (*b).por);
		(*b).por--;
	}
	while ((*b).por > -1 && (*b).m > -1)
	{
		if (z.t_double.m >> (*b).m & 1)
		{
			buf = arif_degree(2, (*b).por);
			arif_plus(one, buf);
			free(buf);
		}
		(*b).por--;
		(*b).m--;
	}
	return (one);
}

char		*sw_round(char *two, int prec, int *f)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * 349);
	s[348] = '\0';
	memset(s, '0', 348);
	s[prec] = '5';
	*f = arif_plus(s, two);
	return (s);
}

void		set_two_continue(char **two, int prec, int *f)
{
	char *s;
	char *buf;

	s = *two;
	buf = s;
	s = sw_round(s, prec, f);
	free(buf);
	buf = s;
	s = ft_strsub(buf, 0, prec);
	*two = s;
	free(buf);
}
