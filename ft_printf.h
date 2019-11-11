/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:32:32 by nsheev            #+#    #+#             */
/*   Updated: 2019/11/11 19:58:33 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdint.h>
# include <stdarg.h>
# include <float.h>
# include <limits.h>

# define RESET      "\033[0m"
# define BOLD       "\033[1m"
# define BLACK      "\033[30;1m"
# define RED        "\033[31;1m"
# define GREEN      "\033[32;1m"
# define YELLOW     "\033[33;1m"
# define BLUE       "\033[34;1m"
# define PURPLE     "\033[35;1m"
# define CYAN       "\033[36;1m"
# define WHITE      "\033[37;1m"

typedef struct		s_ofl
{
	int				k;
	int				len;
	int				g;
}					t_ofl;

typedef struct		s_flags
{
	int				grid;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				l;
	int				lbig;
	int				h;
	int				width;
	int				precision;
}					t_flags;

typedef struct		s_buf_fl
{
	char			buf;
	struct s_buf_fl	*next;
}					t_buf_fl;

union				u_common
{
	double			c;
	int64_t			i;
	struct			s_double
	{
		long int	m:52;
		int			p:11;
		int			s:1;
	}				t_double;
};

typedef struct		s_byte
{
	int				m;
	int				p;
	int				por;
	int				f;
}					t_byte;

union				u_double
{
	void			*p;
	int64_t			byte;
};

typedef struct		s_o_struc
{
	int k;
	int len;
	int g;
}					t_o_struc;

void				color(char **format);
int					ft_printf(const char *format, ...);
int					sw_p_flag(void *a, t_flags *l, int len, int i);
int					sw_s_flag(char *s, t_flags *l, int i, int f);
int					sw_x_flag_ll(unsigned long long a, t_flags *l);
int					sw_x_flag_l(unsigned long a, t_flags *l);
int					sw_x_flag(unsigned a, t_flags *l);
int					sw_x_big_flag_ll(unsigned long long a, t_flags *l);
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
t_byte				set_byte_srtuct(union u_common z);
void				sw_increase(char *one);
char				*set_one(t_byte *b, union u_common z);
char				*sw_round(char *two, int prec, int *f);
void				set_two_continue(char **two, int prec, int *f);
char				*set_two(t_byte b, union u_common z, int prec, int *f);
char				**set_num(union u_common z, int prec);
void				sw_check_sign(int *len, int *i, t_flags *l,
						union u_common z);
void				sw_ft_putnbr_ll(long long nb);
void				print_hex(unsigned a, unsigned base);
int					sw_0if_zero(t_flags *l);
int					sw_i_flag_l(long a, t_flags *l);
int					sw_i_flag(int a, t_flags *l);
int					sw_u_flag_ll(unsigned long long a, t_flags *l);
int					sw_o_flag_ll(unsigned long long a, t_flags *l);
int					sw_i_flag_h(short a, t_flags *l);
int					sw_i_flag_hh(char a, t_flags *l);
int					sw_u_flag(unsigned a, t_flags *l);
int					sw_u_flag_h(unsigned short a, t_flags *l);
int					sw_u_flag_hh(unsigned char a, t_flags *l);
int					sw_u_flag_l(unsigned long a, t_flags *l);
unsigned long		sw_degree_1(unsigned long base, int i);
void				sw_ft_putnbr_l(long nb);
int					sw_length_l(long a);
void				sw_ft_putnbr_ll(long long nb);
int					sw_length_ll(long long a);
void				sw_ft_putnbr_i(int nb);
int					sw_length_i(int a);
void				sw_ft_putnbr_i_hh(char nb);
int					sw_length_hh(char a);
void				sw_ft_putnbr_i_h(short nb);
int					sw_length_h(short a);
void				sw_ft_putnbr_u_h(unsigned short nb);
void				sw_ft_putnbr_u_hh(unsigned char nb);
void				sw_ft_putnbr_u_l(unsigned long nb);
void				sw_ft_putnbr_u_ll(unsigned long long nb);
void				sw_ft_putnbr_u_cas(unsigned nb);
void				len_print_hex_x_big_ll(unsigned long long a,
						unsigned base, int *k);
void				print_hex_x_big_ll(unsigned long long a, unsigned base);
void				len_print_hex_x_ll(unsigned long long a,
						unsigned base, int *k);
void				print_hex_x_ll(unsigned long long a,
						unsigned base);
void				len_print_hex_x_l(unsigned long a, unsigned base, int *k);
void				print_hex_x_l(unsigned long a, unsigned base);
void				len_print_hex_x(unsigned a, unsigned base, int *k);
void				print_hex_x(unsigned a, unsigned base);
void				len_print_hex_o_ll(unsigned long long a,
						unsigned base, int *k);
void				long_print_hex_len(unsigned long int a,
						unsigned long base, int *k);
void				long_print_hex(unsigned long a, unsigned long base);
int					if_p_null(t_flags *l);
int					sw_ifzero_o(t_flags *l);
void				len_print_hex_ll_o_o(unsigned long long a,
						unsigned base, int *k);
void				print_hex_ll_o(unsigned long long a, unsigned base);
void				sw_set_param_o_cas(t_flags *l, unsigned long long a,
						t_o_struc *z);
void				sw_000(t_flags *l, int *i);
int					qwerty(char **buf, t_flags **flag);

#endif
