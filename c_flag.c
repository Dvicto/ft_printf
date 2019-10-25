#include "ft_printf.h"

int			c_flag(char c, t_flags *flag)
{
    char	*str;

	if (flag->width != 0)
		str = ft_strnew((size_t) flag->width);
	if (flag->minus != 0 && flag->width > 1)
	{
		str = ft_add_char(str, c);
		while (flag->width != 1)
		{
			str = ft_add_char(str, ' ');
			flag->width--;
		}
	}
	else if (flag->width > 1)
		c_flag_1(c, flag, &str);
	return final_putstr(str);
}

void	c_flag_1(char c, t_flags *flag, char **str)
{
	if (flag->zero != 0)
	{
		while (flag->width != 1){
			(*str) = ft_add_char((*str), '0');
			flag->width--;
		}
		(*str) = ft_add_char((*str), c);
	}
	else {
		while (flag->width != 1){
			(*str) = ft_add_char((*str), ' ');
			flag->width--;
		}
		(*str) = ft_add_char((*str), c);
	}
}