#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void	len_print_hex(int a, int base, int *k)
{
	if (a > base - 1)
		len_print_hex(a / base, base, k);
	(*k)++;
}

void	print_hex(int a, int base)
{
	char s[17] = "0123456789abcdef";
	if (a > base - 1)
		print_hex(a / base, base);
	write(1, &s[a % base], 1);
}

int		sw_o_flag(int a, t_flags *l)
{
	int		k;
	int		len;
	int		sign;
	int		prec;
	int		i;

	if (l->zero && l->precision)
		l->zero = 0;
	prec = 0;
	sign = 0;
	k = 0;
	if (l->grid)
		len++;
	if (a < 0)
	{
		sign++;
		a = -a;
	}
	len_print_hex(a, 16, &k);
	len = k;
	if (l->grid)
		len += 2;
	if (len < l->precision)
	{
		prec++;
		len = l->precision;
	}
	if (!l->minus)
	{
		while (l->width > len)
		{
			if (l->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			i++;
			l->width--;
		}
	}
	if ( l->zero)
	{
		while(l->width > len)
		{
			write(1, "0", 1);
			i++;
			l->width--;
		}
	}
	if (prec)
	{
		while (l->precision > k + l->grid)
		{
			write(1, "0", 1);
			i++;
			l->precision--;
			l->width--;
		}
	}
	if (l->grid)
	{
		write(1, "0x", 2);
		i++;
		l->width--;
	}
	print_hex(a, 16);
	i = i + k;
	l->width = l->width - k;
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}

int main()
{
	t_flags	*l;

	l = (t_flags *)malloc(sizeof(t_flags));
	l->grid = 1;
	l->precision = 0;
	l->zero = 0;
	l->width = 0;
	l->minus = 0;
	l->space = 0;
	l->plus = 0;
	int a = 12964;

	sw_o_flag(a, l);
	printf(" end\n%#x end\n", a);
	return(0);
}