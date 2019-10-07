#include "./libft/libft.h"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list  vl;
    char    *str;

    va_start(vl, format);
    str = (char *)va_arg(vl, char *);
    ft_putnbr((int)va_arg(vl, int));
    ft_putstr(str);
    return (0);
}

int main()
{
    ft_printf("", "2er234r", 123);
    return (0);
}