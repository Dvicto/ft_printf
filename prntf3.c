/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:35:38 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/11 17:27:43 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lets_go_dioux(va_list vl, t_flags **flag, char spec)
{
	if (spec == 'd' || spec == 'i')
		return (lets_go_d(vl, flag));
	if (spec == 'o')
		return (lets_go_o(vl, flag));
	if (spec == 'u')
	{
		(*flag)->space = 0;
		return (lets_go_u(vl, flag));
	}
	if (spec == 'x')
		return (lets_go_x(vl, flag));
	if (spec == 'X')
		return (lets_go_x_big(vl, flag));
	return (0);
}

int		lets_go_fcsp(va_list vl, t_flags **flag, char spec)
{
	long double a;

	if (spec == 's')
		return (sw_s_flag(va_arg(vl, char*), *flag, 0, 0));
	if (spec == 'p')
		return (sw_p_flag(va_arg(vl, void*), *flag, 0, 0));
	if (spec == 'c')
		return (c_flag((char)va_arg(vl, int), *flag));
	if (spec == 'f')
	{
		if ((*flag)->lbig)
		{
			a = va_arg(vl, long double);
			if (a == -LDBL_MIN)
				a = -DBL_MIN;
			return (sw_f_flag((double)a, *flag));
		}
		return (sw_f_flag(va_arg(vl, double), *flag));
	}
	return (0);
}

t_flags	*newflags(t_flags **flag)
{
	*flag = malloc(sizeof(t_flags));
	(*flag)->grid = 0;
	(*flag)->zero = 0;
	(*flag)->minus = 0;
	(*flag)->plus = 0;
	(*flag)->space = 0;
	(*flag)->l = 0;
	(*flag)->lbig = 0;
	(*flag)->h = 0;
	(*flag)->width = 0;
	(*flag)->precision = -1;
	return (*flag);
}
