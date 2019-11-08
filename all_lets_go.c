/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_lets_go.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:07:36 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/08 20:23:55 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					lets_go_d(va_list vl, t_flags **flag)
{
	short			a;
	char			b;

	if ((*flag)->h == 1)
	{
		a = (short)va_arg(vl, int);
		return (sw_i_flag_h(a, *flag));
	}
	if ((*flag)->h == 2)
	{
		b = (char)va_arg(vl, int);
		return (sw_i_flag_hh(b, *flag));
	}
	if ((*flag)->l == 1)
		return (sw_i_flag_l(va_arg(vl, long), *flag));
	if ((*flag)->l == 2)
		return (sw_i_flag_ll(va_arg(vl, long long), *flag));
	return (sw_i_flag(va_arg(vl, int), *flag));
}

int					lets_go_o(va_list vl, t_flags **flag)
{
	unsigned short	a;
	unsigned char	b;

	if ((*flag)->h == 1)
	{
		a = (unsigned short)va_arg(vl, unsigned);
		return (sw_o_flag_h(a, *flag));
	}
	if ((*flag)->h == 2)
	{
		b = (unsigned char)va_arg(vl, unsigned);
		return (sw_o_flag_hh(b, *flag));
	}
	if ((*flag)->l == 1)
		return (sw_o_flag_l(va_arg(vl, unsigned long), *flag));
	if ((*flag)->l == 2)
		return (sw_o_flag_l(va_arg(vl, unsigned long), *flag));
	return (sw_o_flag_ll((unsigned)va_arg(vl, unsigned long long), *flag));
}

int					lets_go_u(va_list vl, t_flags **flag)
{
	unsigned short	b;
	unsigned char	c;

	if ((*flag)->h == 1)
	{
		b = (unsigned short)va_arg(vl, unsigned);
		return (sw_u_flag_h(b, *flag));
	}
	if ((*flag)->h == 2)
	{
		c = (unsigned char)va_arg(vl, unsigned);
		return (sw_u_flag_hh(c, *flag));
	}
	if ((*flag)->l == 1)
		return (sw_u_flag_l(va_arg(vl, unsigned long), *flag));
	if ((*flag)->l == 2)
		return (sw_u_flag_ll(va_arg(vl, unsigned long long), *flag));
	return (sw_u_flag(va_arg(vl, unsigned), *flag));
}

int					lets_go_x(va_list vl, t_flags **flag)
{
	unsigned short	a;
	unsigned char	b;

	if ((*flag)->h == 1)
	{
		a = (unsigned short)(va_arg(vl, unsigned));
		return (sw_x_flag((unsigned)a, *flag));
	}
	if ((*flag)->h == 2)
	{
		b = (unsigned char)(va_arg(vl, unsigned));
		return (sw_x_flag((unsigned)b, *flag));
	}
	if ((*flag)->l == 1)
		return (sw_x_flag_l(va_arg(vl, unsigned long), *flag));
	if ((*flag)->l == 2)
		return (sw_x_flag_ll(va_arg(vl, unsigned long long), *flag));
	else
		return (sw_x_flag(va_arg(vl, unsigned), *flag));
}

int					lets_go_x_big(va_list vl, t_flags **flag)
{
	unsigned short	a;
	unsigned char	b;

	if ((*flag)->h == 1)
	{
		a = (unsigned short)(va_arg(vl, unsigned));
		return (sw_x_big_flag_ll((unsigned long long)a, *flag));
	}
	if ((*flag)->h == 2)
	{
		b = (unsigned char)(va_arg(vl, unsigned));
		return (sw_x_big_flag_ll((unsigned long long)b, *flag));
	}
	if ((*flag)->l == 1)
	{
		return (sw_x_big_flag_ll((unsigned long long)va_arg(vl, unsigned long),
			*flag));
	}
	if ((*flag)->l == 2)
		return (sw_x_big_flag_ll(va_arg(vl, unsigned long long), *flag));
	return (sw_x_big_flag_ll((unsigned long long)va_arg(vl, unsigned), *flag));
}
