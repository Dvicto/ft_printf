/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_f_add2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:34:43 by nsheev            #+#    #+#             */
/*   Updated: 2019/11/04 16:33:02 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*set_two(t_byte b, union common z, int prec, int *f)
{
	char	*two;
	char	*buf;

	two = (char*)malloc(sizeof(char) * 349);
	two[348] = '\0';
	memset(two, '0', 348);
	if (b.f == 0)
	{
		free(two);
		two = arif_degree_f(5, -b.por);
		b.por--;
	}
	while (b.m > -1)
	{
		if (z.t_double.m >> b.m & 1)
		{
			buf = arif_degree_f(5, -b.por);
			arif_plus(two, buf);
			free(buf);
		}
		b.por--;
		b.m--;
	}
	set_two_continue(&two, prec, f);
	return (two);
}

char		**set_num(union common z, int prec)
{
	char	**num;
	t_byte	b;
	int		f;
	char	*buf;
	int		i;

	f = 0;
	b = set_byte_srtuct(z);
	num = (char **)malloc(sizeof(char *) * 2);
	num[0] = set_one(&b, z);
	if (prec > 0)
		num[1] = set_two(b, z, prec, &f);
	else
		num[1] = NULL;
	if (f)
		sw_increase(num[0]);
	buf = num[0];
	i = 0;
	while (buf[i] == '0' && i < 347)
		i++;
	num[0] = ft_strsub(buf, i, 349 - i - 1);
	free(buf);
	return (num);
}

void		sw_check_sign(int *len, int *i, t_flags *l, union common z)
{
	if (z.t_double.s || l->space || l->plus)
	{
		if (z.t_double.s)
		{
			write(1, "-", 1);
			(*i)++;
			(*len)--;
			l->width--;
		}
		if (l->plus && !z.t_double.s)
		{
			write(1, "+", 1);
			(*i)++;
			(*len)--;
			l->width--;
		}
		if (l->space && !l->plus && !z.t_double.s)
		{
			write(1, " ", 1);
			(*i)++;
			(*len)--;
			l->width--;
		}
	}
}
