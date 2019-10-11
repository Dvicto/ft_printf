#include "printf.h"

char    *ints(t_flags flags, int num)
{
	char	*numm;
	char	c;

	c = " ";
	numm = ft_itoa(num);
	if (flags.plus == 1 && numm[0] != '-')
		numm = add_start_str(&numm, "+");
	if (flags.space == 1 && numm[0] != '-')
		numm = add_start_str(&numm, " ");
	if (flags.precision > ft_strlen(numm))
	{
		while(flags.precision != ft_strlen(numm))
			numm = add_start_str(&numm, "0");
	}
	if (flags.width > ft_strlen(numm) && flags.minus != 1)
	{
		if (flags.zero == 1)
			c = "0";
		while (flags.width != ft_strlen(numm))
			numm = add_start_str(&numm, c);
	}
	if (flags.width > ft_strlen(numm) && flags.minus == 1)
	{	
		while (flags.width != ft_strlen(numm))
			numm = add_start_str(" ", &numm);
	}
	if (flags.precision < ft_strlen(numm))
	{
		numm = str_cut(numm, (int)ft_strlen(numm) - flags.precision)
	}
	if (flags.width < ft_strlen(numm))
	{
		numm = str_cut(numm, (int)ft_strlen(numm) - flags.precision)
	}
}

//!!!!!!!!!!!!lints((long long)int)

char    *lints(t_flags flags, long long int num)
{
	char	*numm;
	char	c;

	c = " ";
	numm = ft_llitoa(num);
	if (flags.plus == 1 && numm[0] != '-')
		numm = add_start_str(&numm, "+");
	if (flags.space == 1 && numm[0] != '-')
		numm = add_start_str(&numm, " ");
	if (flags.precision > ft_strlen(numm))
	{
		while(flags.precision != ft_strlen(numm))
			numm = add_start_str(&numm, "0");
	}
	if (flags.width > ft_strlen(numm) && flags.minus != 1)
	{
		if (flags.zero == 1)
			c = "0";
		while (flags.width != ft_strlen(numm))
			numm = add_start_str(&numm, c);
	}
	if (flags.width > ft_strlen(numm) && flags.minus == 1)
	{	
		while (flags.width != ft_strlen(numm))
			numm = add_start_str(" ", &numm);
	}
	if (flags.precision < ft_strlen(numm))
	{
		numm = str_cut(numm, (int)ft_strlen(numm) - flags.precision)
	}
	if (flags.width < ft_strlen(numm))
	{
		numm = str_cut(numm, (int)ft_strlen(numm) - flags.precision)
	}
}

char    *llints(t_flags flags, long num)
{
	char	*numm;
	char	c;

	c = " ";
	numm = ft_litoa(num);
	if (flags.plus == 1 && numm[0] != '-')
		numm = add_start_str(&numm, "+");
	if (flags.space == 1 && numm[0] != '-')
		numm = add_start_str(&numm, " ");
	if (flags.precision > ft_strlen(numm))
	{
		while(flags.precision != ft_strlen(numm))
			numm = add_start_str(&numm, "0");
	}
	if (flags.width > ft_strlen(numm) && flags.minus != 1)
	{
		if (flags.zero == 1)
			c = "0";
		while (flags.width != ft_strlen(numm))
			numm = add_start_str(&numm, c);
	}
	if (flags.width > ft_strlen(numm) && flags.minus == 1)
	{	
		while (flags.width != ft_strlen(numm))
			numm = add_start_str(" ", &numm);
	}
	if (flags.precision < ft_strlen(numm))
	{
		numm = str_cut(numm, (int)ft_strlen(numm) - flags.precision)
	}
	if (flags.width < ft_strlen(numm))
	{
		numm = str_cut(numm, (int)ft_strlen(numm) - flags.precision)
	}
}

char	*str_cut(char **str, int n)
{
	char	*newstr;
	int		i;
	int		j;
	
	i = 0;
	j = (int)ft_strlen(str) - n;
	newstr = (char *)ft_memalloc(j + 1);
	while (i < j)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	free(*str);
	return newstr;
}

char    *add_start_str(char **str, char **added)
{
    char    *newstr;
    int     i;
    int     j;

    i = 0;
    j = 0;
    newstr = (char *)ft_memalloc(ft_strlen(str) + ft_strlen(added) + 1);
    while (i < ft_strlen(added))
    {
        newstr[i] = added[i];
        i++;
    }
    while (j < ft_strlen(str))
    {
        newstr[i] = str[j];
        i++;
        j++;
    }
    newstr[i] = '\0';
    free(*str);
    free(*added);
    return newstr;
}

int main()
{
    char    *a;
    char    *b;
    a = ft_memalloc(10);
    b = ft_memalloc(10);
    a = "pidr";
    b = "sanya";
    printf("%s", add_start_str(a, "+"));
    printf("%-7.5d", 123);
    return 0;
}