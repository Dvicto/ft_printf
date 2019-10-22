#include "flags.h"

union u_double
{
	void	*p;
	int64_t	byte;
};

long int	sw_degree(long int base, int i)
{
	long int	sw;

	sw = 1;
	while (i)
	{
		sw = sw * base;
		i--;
	}
	return (sw);
}

void	long_print_hex(long int a, int base)
{
	char s[17] = "0123456789abcdef";
	if (a > base - 1)
		long_print_hex(a / base, base);
	write(1, &s[a % base], 1);
}

int		sw_p_flag(void *a, t_flags *l)
{
	union	u_double z;
	long	num;
	int		sw;
	int		len;
	int		i;

	z = (union u_double)malloc(sizeof(union u_double));
	sw = 63;
	i = 0;
	num = 0;
	z.p = a;
	len = 14;
	while (sw > -1)
	{
		if (z.byte >> sw & 1)
			num = num + sw_degree(2, sw);
		sw--;
	}
	if (l->precision > -1 || l->minus)
		l->zero = 0;
	if (l->precision > 12)
		len = l->precision + 2;
	if (l->plus || l->space)
		len++;
	if (l->zero && l->width > len)
		len = l->width;
	if (a == NULL)
	{
		if (l->minus)
		{
			write(1, "(nil)", 5);
			while (l->width - 5 > 0)
			{
				write(1, " ", 1);
				l->width--;
			}
		}
		else
		{
			while (l->width - 5 > 0)
			{
				write(1, " ", 1);
				l->width--;
			}
			write(1, "(nil)", 5);
		}
		if (l->width < 5)
			return (5);
		else
			return (l->width);
	}
	while (l->width > len && !l->minus)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	if (l->plus)
	{
		write(1, "+", 1);
		i++;
		len--;
		l->width--;
	}
	if (l->space && !l->plus)
	{
		write(1, " ", 1);
		i++;
		len--;
		l->width--;
	}
	write(1, "0x", 2);
	i += 2;
	len -= 2;
	l->width -= 2;
	while (l->zero && l->width > 12)
	{
		write(1, "0", 1);
		i++;
		len--;
		l->width--;
	}
	while (l->precision > 12)
	{
		write(1, "0", 1);
		i++;
		len--;
		l->precision--;
		l->width--;
	}
	long_print_hex(num, 16);
	i += 12;
	l->width -= 12;
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}
