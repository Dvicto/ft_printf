#include "printf.h"

int     final_putstr(char *str)
{
    int     i;
    i = ft_strlen(str);
    write(1, str, i);
    return (i);
}

int     final_putchar(char c)
{
    if (c)
        write(1, &c, 1);
    return (1);
}