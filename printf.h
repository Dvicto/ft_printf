#include "./libft/libft.a"

typedef struct	s_flags
{
	int			grid;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			l;
	int			ll;
	int			h;
	int			width;
	int			precision;
}				t_flags;

typedef struct	s_buf_fl
{
	char		buf;
	s_buf_fl	*next;
}				t_buf_fl;
