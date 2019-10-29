#include "ft_printf.h"

int		lets_go_d(va_list vl, t_flags **flag)
{
	if ((*flag)->h == 1)
		return (sw_i_flag_h(va_arg(vl, short), *flag));
	if ((*flag)->h == 2)
		return (sw_i_flag_hh(va_arg(vl, char), *flag));
	if ((*flag)->l == 1)
		return (sw_i_flag_l(va_arg(vl, long), *flag));
	if ((*flag)->l == 2)
		return (sw_i_flag_ll(va_arg(vl, long long), *flag));
	return (sw_i_flag_h(va_arg(vl, int), *flag));
}

int		lets_go_o(va_list vl, t_flags **flag)
{
	if ((*flag)->h == 1)
		return (sw_o_flag_h(va_arg(vl, short unsigned), *flag));
	if ((*flag)->h == 2)
		return (sw_o_flag_hh(va_arg(vl, char unsigned), *flag));
	if ((*flag)->l == 1)
		return (sw_o_flag_l(va_arg(vl, long unsigned), *flag));
	if ((*flag)->l == 2)
		return (sw_o_flag_ll(va_arg(vl, long long unsigned), *flag));
	return (sw_o_flag_h(va_arg(vl, unsigned), *flag));
}

int		lets_go_u(va_list vl, t_flags **flag)
{
	if ((*flag)->h == 1)
		return (sw_u_flag_h(va_arg(vl, short unsigned), *flag));
	if ((*flag)->h == 2)
		return (sw_u_flag_hh(va_arg(vl, char unsigned), *flag));
	if ((*flag)->l == 1)
		return (sw_u_flag_l(va_arg(vl, long unsigned), *flag));
	if ((*flag)->l == 2)
		return (sw_u_flag_ll(va_arg(vl, long long unsigned), *flag));
	return (sw_u_flag_h(va_arg(vl, unsigned), *flag));
}

int		lets_go_x(va_list vl, t_flags **flag)
{
	if ((*flag)->h == 1)
		return (sw_x_flag_h(va_arg(vl, short unsigned), *flag));
	if ((*flag)->h == 2)
		return (sw_x_flag_hh(va_arg(vl, char unsigned), *flag));
	if ((*flag)->l == 1)
		return (sw_x_flag_l(va_arg(vl, long unsigned), *flag));
	if ((*flag)->l == 2)
		return (sw_x_flag_ll(va_arg(vl, long long unsigned), *flag));
	return (sw_x_flag_h(va_arg(vl, unsigned), *flag));
}

int		lets_go_x_big(va_list vl, t_flags **flag)
{
	if ((*flag)->h == 1)
		return (sw_x_flag_h(va_arg(vl, short unsigned), *flag));
	if ((*flag)->h == 2)
		return (sw_x_flag_hh(va_arg(vl, char unsigned), *flag));
	if ((*flag)->l == 1)
		return (sw_x_flag_l(va_arg(vl, long unsigned), *flag));
	if ((*flag)->l == 2)
		return (sw_x_flag_ll(va_arg(vl, long long unsigned), *flag));
	return (sw_x_flag_h(va_arg(vl, unsigned), *flag));
}