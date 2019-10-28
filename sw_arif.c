/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_arif.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:59:21 by nsheev            #+#    #+#             */
/*   Updated: 2019/10/28 17:28:36 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		arif_plus(char *s, char *s1)
{
	int i;
	int l;
	int m;

	i = 347;
	l = 0;
	while (i > -1)
	{
		m = s[i] - '0' + s1[i] - '0' + l;
		s[i] = m % 10 + '0';
		l = m / 10;
		i--;
	}
	return (l);
}

void	arif_unmoz(char *s, int a)
{
	int i;
	int l;
	int m;

	i = 347;
	l = 0;
	m = (s[i] - '0') * a;
	s[i] = ((s[i] - '0') * a) % 10 + '0';
	l = m / 10 + s[i - 1] - '0';
	while (i > 1)
	{
		i--;
		m = s[i] - '0' + l;
		s[i] = m % 10 + '0';
		l = m / 10 + s[i - 1] - '0';
	}
}

void	arif_unmoz_f(char *s, int a, int por)
{
	int i;
	int l;
	int m;

	l = 0;
	i = por - 1;
	while (i > -1)
	{
		m = (s[i] - '0') * a + l;
		s[i] = m % 10 + '0';
		l = m / 10;
		i--;
	}
}

char	*arif_degree(int base, int st)
{
	char	*s;
	int		i;

	s = (char*)malloc(sizeof(char) * 349);
	s[348] = '\0';
	memset(s, '0', 348);
	i = 347;
	if (st == 0)
	{
		s[i] = '1';
		return (s);
	}
	if (st > 0)
	{
		s[i] = '1';
		while (st > 0)
		{
			arif_unmoz(s, base);
			st--;
		}
		return (s);
	}
	return (s);
}

char	*arif_degree_f(int base, int st)
{
	int		l;
	char	*s;

	l = st;
	s = (char*)malloc(sizeof(char) * 349);
	s[348] = '\0';
	memset(s, '0', 348);
	s[st - 1] = '1';
	while (st > 0)
	{
		arif_unmoz_f(s, base, l);
		st--;
	}
	return (s);
}
