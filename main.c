#include "./libft/libft.h"
#include <stdarg.h>
#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list  vl;
	char	*forrmat;
	forrmat = (char *)format;

	va_start(vl, format);
	start_printf(vl, forrmat);
	va_end(vl);
	return (0);
}

int		start_printf(va_list vl, char *format)
{
		int	count_symb;
		
		count_symb = 0;
	if (*format == '%' && format[1] == '%')
	{
		//count_symb += final_putchar(format[1]);//out %
		format += 2;
	}
	else if (*format == '%' && !(format[1]))
		return 0;
	else if (*format == '%' && format[1])
		{
			format++;
			count_symb += start_parce(vl, format);
		}
	else
	{
		//count_symb += final_putchar(*format);
		format++;//out text;
	}
	return count_symb;
}

int		start_parce(va_list vl, char *format)
{
	t_flags		*flag;
	char		*buf;
	buf = (char *)ft_memalloc(1);
	flag = newflags();
	while (*format != 'd' && *format != 'i' && *format != 'o' && *format != 'u' && *format != 'x'
		&& *format != 'X' && *format != 'f' && *format != 'c' && *format != 's' && *format != 'p')
	{
		buf = ft_add_char(&buf, *format);
		format++;
	}
	buf = ft_add_char(&buf, *format);
	format++;
	return cont1_parce(vl, buf, flag);
}

t_flags	*parce_flags(char *buf, t_flags *flag)
{
	size_t		i;
	
	i = 0;
	while (i < ft_strlen(buf))
	{
		if (buf[i] == '#')
			flag->grid += 1;
		else if (buf[i] == '-')
			flag->minus += 1;
		else if (buf[i] == '+')
			flag->plus += 1;
		else if (buf[i] == ' ')
			flag->space += 1;
		else if (buf[i] == 'l')
			flag->l += 1;
		else if (buf[i] == 'h')
			flag->h += 1;
		else if (buf[i] == 'L')
			flag->lbig += 1;
		i++;
	}
	flag = parce_flags2(buf, flag);
	return (flag);
}

t_flags *parce_flags2(char *buf, t_flags *flag)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(buf))
	{
		if (buf[0] == '0' || (buf[i] == '0' && (buf[i - 1] < '0' || buf[i - 1] > '9')))
			flag->zero = 1;
		if (buf[i] >= '1' && buf[i] <= '9' && flag->width == 0 && flag->precision == 0)
		{
			flag->width = ft_atoi(buf + i);
			i += ft_lennbr(flag->width);
		}
		if (buf[i] == '.')
			flag = precision(buf, flag);
	}

	return (flag);
}

t_flags	*precision(char *buf, t_flags *flag)
{
	size_t	i;

	i = 0;
	while (buf[i] != '.')
		i++;
	i++;
	flag->precision = ft_atoi(buf + i);
	return (flag);
}

int		cont1_parce(va_list vl, char *buf, t_flags *flag)
{
	char	spec;

	spec = buf[ft_strlen(buf) - 1];       printf("%c", spec);
	flag = parce_flags(buf, flag);		  printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d", flag->grid, flag->zero, flag->minus, flag->plus, flag->space, flag->l, flag->lbig, flag->h, flag->width, flag->precision);
	return 0;
	/*if (spec == 'd' || spec == 'i' || spec == 'o' || spec == 'u' || spec == 'x')
		lets_go_dioux(vl, flag);
	else if (spec == 'X' || spec == 'f' || spec == 'c' || spec == 's' || spec == 'p')
		lest_go_Xfcsp(vl,flag);*/
	
	
}
t_flags	*newflags()
{
	t_flags *flag;
	flag = (t_flags *)malloc(sizeof(t_flags *) * 1);
	flag->grid = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->l = 0;
	flag->lbig = 0;
	flag->h = 0;
	flag->width = 0;
	flag->precision = 0;
	return flag;
}

int main()
{
    ft_printf("%-#d, %-12.41f", 123, 321);
    return (0);
}