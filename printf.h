# include "./libft/libft.h"

typedef struct	s_flags
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
