# include "./libft/libft.h"

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

int					final_putstr(char *str);
int					final_putchar(char c);
int					ft_printf(const char *format, ...);
int					start_printf(va_list vl, char *format);
int					start_parce(va_list vl, char *format);
t_flags				*parce_flags(char *buf, t_flags *flag);
t_flags				*parce_flags2(char *buf, t_flags *flag);
t_flags				*precision(char *buf, t_flags *flag);
int					cont1_parce(va_list vl, char *buf, t_flags *flag);
t_flags				*newflags();

