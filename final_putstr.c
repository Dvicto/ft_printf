int     final_putstr(char *str)
{
    int     i;
    while (str[i] != '\0')
    {
        wtite(1, str[i], 1);
        i++;
    }
    return (i);
}