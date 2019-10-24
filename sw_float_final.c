/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_float_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 00:42:15 by swedde            #+#    #+#             */
/*   Updated: 2019/10/23 13:17:04 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_flags
{
	int				grid;//#
	int				zero;//"0"
	int				minus;//"-"
	int				plus;//"+"
	int				space;//" "
	int				l;//"l   /   ll"
	int				lbig;//"L"
	int				h;//" h     /   hh"
	int				width;
	int				precision;
}					t_flags;

int		sw_len(unsigned long long a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		a /= 10;
	}
	return (i);
}

unsigned long long	sw_degree(unsigned long long base, int i)
{
	unsigned long long	sw;

	sw = 1;
	while (i)
	{
		sw = sw * base;
		i--;
	}
	return (sw);
}

unsigned long long	sw_round(unsigned long long *two)
{
	if (sw_len(*two) == sw_len(*two + 5))
	{
		*two = (*two + 5) / 10;
		return (0);
	}
	else
	{
		*two = *two + 5;
		*two = *two - *two % 10 - sw_degree(10, sw_len(*two) - 1);
		return (1);
	}
}

char	*sw_float(double a, t_flags *l)
{
	char				*s;				//return
	int					i;				//счетчик строки
	unsigned long long	one;			//до точки
	unsigned long long	two;			//после точки
	int					len;			//длина вывода
	int					sign;			//знак
	int					lena;			//вспомогательная
	int					zerodrob;		//число нолей после точки
	int					flzerodrob;		//флаг для округления дробной чаcти

	flzerodrob = 0;
	zerodrob = 0;
	sign = 0;
	if (a < 0)
	{
		a = -a;
		sign = 1;
	}
	one = a;
	a = a - one;
	lena = l->precision + 1;
	while (lena)
	{
		a *= 10;
		two = a;
		if (!two)
		{
			flzerodrob = 1;
			zerodrob++;
		}
		lena--;
	}
	if (two > 0 && sw_round(&two))
	{
		if (flzerodrob == 0)
			one++;
		else
			flzerodrob = 2;
	}
	len = sw_len(one);
	if (len == 0)
		len = 1;
	if (sign || l->plus || l->space)
		len++;
	if (l->precision || l->grid)
		len = len + 1 + l->precision;
	if (len < l->width)
		s = (char *)malloc(sizeof(char) * (l->width + 1));
	else
		s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL); 
	i = 0;
	if (l->minus == 0)
	{
		if (l->zero)
			if (sign || l->plus || l->space)
			{
				if (sign)
					s[i] = '-';
				else if (l->plus == 1)
					s[i] = '+';
				else if (l->space == 1)
					s[i] = ' ';
				i++;
			}
		while (l->width - len > 0)
		{
			if (l->zero == 1)
				s[i] = '0';
			else
				s[i] = ' ';
			i++;
			len++;
		}
		if (!l->zero)
			if (sign || l->plus || l->space)
			{
				if (sign)
					s[i] = '-';
				else if (l->plus == 1)
					s[i] = '+';
				else if (l->space == 1)
					s[i] = ' ';
				i++;
			}
	}
	else
		if (sign || l->plus || l->space)
		{
			if (sign)
				s[i] = '-';
			else if (l->plus == 1)
				s[i] = '+';
			else if (l->space == 1)
				s[i] = ' ';
			i++;
		}
	lena = sw_len(one);
	i = i + lena - 1;
	while (one)
	{
		s[i] = one % 10 + '0';
		one = one / 10;
		i--;
	}
	i = i + lena + 1;
	if (l->precision || l->grid)
	{
		s[i] = '.';
		i++;
	}
	while (zerodrob && i < len && l->precision)
	{
		if (flzerodrob == 2 && zerodrob == 1)
			s[i] = '1';
		else
			s[i] = '0';
		i++;
		zerodrob--;
		l->precision--;
	}
	if (two > 0)
	{
		lena = sw_len(two);
		i = i + lena - 1;
		while (two && i < len && l->precision)
		{
			s[i] = two % 10 + '0';
			two = two / 10;
			i--;
			l->precision--;
		}
		i = i + lena + 1;
	}
	while (i < len && l->precision)
	{
		s[i] = '0';
		i++;
		l->precision--;
	}
	while (l->width > len)
	{
		s[i] = ' ';
		i++;
		len++;
	}
	s[len] = '\0';
	return (s);
}

int main()
{
	float a = -99.799f;
	t_flags	*l;

	l = (t_flags *)malloc(sizeof(t_flags));
	l->grid = 1;
	l->precision = 2;
	l->zero = 0;
	l->width = 10;
	l->minus = 1;
	l->space = 0;
	l->plus = 1;
	char *s = sw_float((double)a, l);
	printf("%sOK\n", s);
	free(s);
	free(l);
	printf("%#-+10.2fOK\n", a);
	return (0);
}
