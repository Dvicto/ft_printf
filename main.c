#include "./libft/libft.h"
#include <stdarg.h>
#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list  vl;

	va_start(vl, format);
	start_printf(vl, format);
	va_end(vl);
	return (0);
}

int		start_printf(va_list vl, char *format)
{
		int	count_symb;
		
		count_symb = 0;
	if (*format == '%' && format[1] == '%')
		count_symb += final_putstr(&format[1]);//out %
	else if (*format == '%' && !(format[1]))
		return ;
	else if (*format == '%' && format[1])
		{
			format++;
			start_pars(vl, buf, format);
		}
	else
	{
		count_symb += final_putstr(&*format);
		format++;//out text;
	}	
}

int		start_parce(va_list vl, char *format)
{
	t_flags		flag;
	while (*format != 'd' |)
	{
		if (*format == '-')
			flag.minus = 1;
		else if (*format == '+')
			flag.plus = 1;
		else if (*format == '#')
			flag.grid = 1;
		else if (*format == '0')
			flag.zero = 1;
	}
}

t_flags	*newflags(t_flags	flag)
{
	flag = (t_flags)malloc(sizeof(1));
	flag.grid = 0;
	flag.zero = 0;
	flag.minus = 0;
	flag.plus = 0;
	flag.space = 0;
	flag.l = 0;
	flag.lbig = 0;
	flag.h = 0;
	flag.width = 0;
	flag.precision = 0;
	return flag;
}

int main()
{
    ft_printf("", "2er234r", 123);
    return (0);
}