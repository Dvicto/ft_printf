/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:32:32 by nsheev            #+#    #+#             */
/*   Updated: 2019/10/30 17:55:21 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "./libft/libft.h"
#include <stdint.h>
#include <stdarg.h>

typedef struct		s_flags
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

typedef struct		s_buf_fl
{
	char			buf;
	struct s_buf_fl	*next;
}					t_buf_fl;

union	common
{
	double c;
	int64_t i;
	struct s_double
	{
		long int	m:52;
		int			p:11;
		int			s:1;
	}t_double;
};

typedef struct	s_byte
{
	int				m;
	int				p;
	int				por;
	int				f;
}				t_byte;

int					ft_printf(const char *format, ...);
int					sw_p_flag(void *a, t_flags *l);
int					sw_s_flag(char *s, t_flags *l);
int					sw_x_flag(unsigned a, t_flags *l);
void				len_print_hex(unsigned a, unsigned base, int *k);
void				print_hex(unsigned a, unsigned base);


int					final_putstr(char *str);
int					final_putchar(char c);
int					ft_printf(const char *format, ...);
int					start_printf(va_list vl, char **format, int count_symb);
int					start_parce(va_list vl, char **format);
void				parce_flags(char *buf, t_flags **flag);
void				parce_flags2(char *buf, t_flags **flag);
void				precision(char *buf, t_flags **flag);
int					cont1_parce(va_list vl, char *buf, t_flags **flag);
t_flags				*newflags();

int					sw_i_flag_ll(long long a, t_flags *l);
char				*str_cut(char *str, int n);
//char				*add_start_str(char *str, char *added);
char				*add_start_char(char **str, char c);

int					lets_go_dioux(va_list vl, t_flags **flag, char spec);
int					lets_go_fcsp(va_list vl, t_flags **flag, char spec);
int					lets_go_d(va_list vl, t_flags **flag);
int					lets_go_o(va_list vl, t_flags **flag);
int					lets_go_u(va_list vl, t_flags **flag);
int					lets_go_x(va_list vl, t_flags **flag);
int					lets_go_x_big(va_list vl, t_flags **flag);

int					c_flag(char c, t_flags *flag);
void				c_flag_1(char c, t_flags *flag, char **str);
int					arif_plus(char *s, char *s1);
void				arif_unmoz(char *s, int a);
void				arif_unmoz_f(char *s, int a, int por);
char				*arif_degree(int base, int st);
char				*arif_degree_f(int base, int st);
int					sw_f_flag(double a, t_flags *l);
int					sw_degree(int base, int i);
t_byte				set_byte_srtuct(union common z);
void				sw_increase(char *one);
char				*set_one(t_byte *b, union common z);
char				*sw_round(char *two, int prec, int *f);
void				set_two_continue(char **two, int prec, int *f);
char				*set_two(t_byte b, union common z, int prec, int *f);
char				**set_num(union common z, int prec);
void				sw_check_sign(int *len, int *i, t_flags *l, union common z);
void				sw_ft_putnbr_ll(long long nb);
void				print_hex(unsigned a, unsigned base);

int					sw_0if_zero(t_flags *l);
int					sw_i_flag_l(long a, t_flags *l);
int					sw_i_flag(int a, t_flags *l);
int					sw_u_flag_ll(unsigned long long a, t_flags *l);
int					sw_o_flag_ll(unsigned long long a, t_flags *l);
int					sw_o_flag_l(unsigned long a, t_flags *l);

#endif