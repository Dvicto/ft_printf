#include "ft_printf.h"

int				write_n_chars(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (n);
}

int				c_flag(char c, t_flags *flag)
{
	int		n;

	n = 0;
	if (!flag->minus && flag->width > 1)
	{
		if (flag->zero)
			n += write_n_chars('0', flag->width - 1);
		else
			n += write_n_chars(' ', flag->width - 1);
	}
	write(1, &c, 1);
	n++;
	if (flag->minus && flag->width > 1)
		n += write_n_chars(' ', flag->width - 1);
	return (n);
}