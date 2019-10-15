#include "printf.h"

int     final_putstr(char *str)
{
    int     i;
    i = 0;
    while (str[i] != '\0')
    {
        wtite(1, str[i], 1);
        i++;
    }
    return (i);
}

int     final_putchar(char c)
{
    if (c)
        write(1, &c, 1);
    return (1);
}