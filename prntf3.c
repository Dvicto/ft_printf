/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:35:38 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/23 14:40:08 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lets_go_dioux(va_list vl, t_flags **flag, char spec)
{
	if (spec == 'd')
		return (final_putstr(ints(flag, va_arg(vl, int))));
	if (spec == 'o')
		return (sw_o_flag(va_arg(vl, unsigned), *flag));
	//if (spec == 'i')
		//return final_putstr(ints(flag, va_arg(vl, int)));
	//if (spec == 'u')
		//return sw_u_flag(va_arg(vl, unsigned), *flag);
	if (spec == 'x')
		return (sw_x_flag(va_arg(vl, unsigned), *flag));
	return (0);
}

int		lets_go_xfcsp(va_list vl, t_flags **flag, char spec)
{
	if (spec == 's')
		return (sw_s_flag(va_arg(vl, char*), *flag));
	if (spec == 'p')
		return (sw_p_flag(va_arg(vl, void*), *flag));
	if (spec == 'c')
		return (final_putchar(va_arg(vl, int)));
	//if (spec == 'f')
		//return sw_f_flag(va_arg(vl, double), *flag);
	//if (spec == 'X')
		//return sw_X_flag(va_arg(vl, unsigned), *flag);
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
