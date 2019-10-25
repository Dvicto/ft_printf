#include "./libft/libft.h"
#include <stdint.h>
#include <stdarg.h>

typedef struct	s_flags
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

int					ft_printf(const char *format, ...);
int					sw_o_flag(unsigned a, t_flags *l);
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

int					sw_i_flag(long long a, t_flags *l);
char				*str_cut(char *str, int n);
//char				*add_start_str(char *str, char *added);
char				*add_start_char(char **str, char c);

int					lets_go_dioux(va_list vl, t_flags **flag, char spec);
int					lets_go_xfcsp(va_list vl, t_flags **flag, char spec);

int					c_flag(char c, t_flags *flag);
void				c_flag_1(char c, t_flags *flag, char **str);

