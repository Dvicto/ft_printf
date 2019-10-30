/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:35:38 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/30 16:17:16 by nsheev           ###   ########.fr       */
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
		return (sw_u_flag_ll(va_arg(vl, unsigned long long), *flag));
/*	if (spec == 'x')
		return (lets_go_x(vl, flag));
	if (spec == 'X')
		return (lets_go_x_big(vl, flag));
	return (0);*/
}

int		lets_go_fcsp(va_list vl, t_flags **flag, char spec)
{
	if (spec == 's')
		return (sw_s_flag(va_arg(vl, char*), *flag));
	if (spec == 'p')
		return (sw_p_flag(va_arg(vl, void*), *flag));
	if (spec == 'c')
		return (c_flag((char)va_arg(vl, int), *flag));
	if (spec == 'f')
		return sw_f_flag(va_arg(vl, double), *flag);
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
