/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swedde <swedde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 00:42:15 by swedde            #+#    #+#             */
/*   Updated: 2019/10/10 03:26:45 by swedde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		sw_len(int a)
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

int		sw_degree(int base, int i)
{
	int		sw;

	sw = 1;
	while (i)
	{
		sw = sw * base;
		i--;
	}
	return (sw);
}

int		sw_round(int *two)
{
	if (sw_len(*two) == sw_len(*two + 5))
	{
		*two = *two + 5;
		return (0);
	}
	else
	{
		*two = *two + 5;
		*two = *two - *two % 10 - sw_degree(10, sw_len(*two) - 1);
		return (1);
	}
}

char	*sw_float(float a, int width, int precision)
{
	char	*s;
	int		i;
	int		one;
	int		two;
	int		len;
	int		sign;
	int		lena;

	sign = 0;
	if (a < 0)
	{
		a = -a;
		sign = 1;
	}
	one = (int)a;
	a = a - (float)one;
	two = (int)(a * sw_degree(10, precision + 1));
	if (sw_round(&two))
		one++;
	printf("%d.%d\n", one, two);
	len = sw_len(one);
	if (len == 0)
		len = 1;
	if (sign)
		len++;
	if (precision)
		len = len + 1 + precision;
	s = (char *)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	i = 0;
	if (sign)
	{
		s[i] = '-';
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
	printf("i = %d\n", i);
	if (precision)
	{
		s[i] = '.';
		i++;
	}
	while (two)
	{
		s[i] = two / sw_degree(10, sw_len(two) - 1) + '0';
		two = two % sw_degree(10, sw_len(two) - 1);
		i++;
	}
	while (i < len)
	{
		s[i] = '0';
		i++;
	}
	return (s);
}

int main()
{
	float a = -69.99999;
	printf("%s\n", sw_float(a, 1, 7));
	printf("%.7f\n", a);
	return (0);
}