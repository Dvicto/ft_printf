#include "./libft/libft.h"
#include <stdarg.h>
#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list  vl;
	char    *buf;

	va_start(vl, format);
	start_printf(vl, buf,format);
	va_end(vl);
	return (0);
}

int		start_printf(va_list vl, char *buf, char *format)
{
	if (*format == '%' && format[1] == '%')
		1;//out %
	else if (*format == '%' && !(format[1]))
		return ;
	else if (*format == '%' && format[1])
		{
			format++;
			start_pars(vl, buf, format);
		}
	else
		1;//out text;
}

int		start_parce(va_list vl, char *buf, char *format)
{
	t_flags		flag;
	while (*format != '%' && *format)
	{

	}
}

int main()
{
    ft_printf("", "2er234r", 123);
    return (0);
}