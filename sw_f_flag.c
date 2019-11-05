/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_f_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:48:48 by nsheev            #+#    #+#             */
/*   Updated: 2019/11/05 15:34:23 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			sw_if_minus(int len, t_flags *l, char **num, union common z)
{
	int i;

	i = 0;
	sw_check_sign(&len, &i, l, z);
	write(1, num[0], strlen(num[0]));
	i += strlen(num[0]);
	l->width -= strlen(num[0]);
	if (l->grid)
	{
		write(1, ".", 1);
		i++;
		len--;
		l->width--;
	}
	write(1, num[1], strlen(num[1]));
	i += strlen(num[1]);
	l->width -= strlen(num[1]);
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}

int			sw_if_zero(int len, t_flags *l, char **num, union common z)
{
	int i;

	i = 0;
	sw_check_sign(&len, &i, l, z);
	while (l->width > len)
	{
		write(1, "0", 1);
		i++;
		l->width--;
	}
	write(1, num[0], strlen(num[0]));
	i += strlen(num[0]);
	l->width -= strlen(num[0]);
	if (l->grid)
	{
		write(1, ".", 1);
		i++;
		len--;
		l->width--;
	}
	write(1, num[1], strlen(num[1]));
	i += strlen(num[1]);
	l->width -= strlen(num[1]);
	return (i);
}

int			sw_if_else(int len, t_flags *l, char **num, union common z)
{
	int i;

	i = 0;
	while (l->width > len)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	sw_check_sign(&len, &i, l, z);
	write(1, num[0], strlen(num[0]));
	i += strlen(num[0]);
	l->width -= strlen(num[0]);
	if (l->grid)
	{
		write(1, ".", 1);
		i++;
		len--;
		l->width--;
	}
	write(1, num[1], strlen(num[1]));
	i += strlen(num[1]);
	l->width -= strlen(num[1]);
	return (i);
}

void		sw_del_ar(char ***num)
{
	if (*num)
	{
		if ((*num)[0] != NULL)
			free((*num)[0]);
		if ((*num)[1] != NULL)
			free((*num)[1]);
		free(*num);
	}
}

int			sw_f_flag(double a, t_flags *l)
{
	union common	z;
	char			**num;
	int				i;
	int				len;

	z.c = a;
	if (l->precision == -1)
		l->precision = 6;
	if (l->minus)
		l->zero = 0;
	if (l->precision > 0)
		l->grid = 1;
	num = set_num(z, l->precision);
	len = strlen(num[0]) + l->grid + l->precision;
	if ((l->plus || l->space) || z.t_double.s)
		len++;
	if (l->minus)
		i = sw_if_minus(len, l, num, z);
	else if (l->zero)
		i = sw_if_zero(len, l, num, z);
	else
		i = sw_if_else(len, l, num, z);
	sw_del_ar(&num);
	return (i);
}
