#include "./libft/libft.h"
#include <stdarg.h>
#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list  vl;
	char	*forrmat;
	int		num = -1;
	int 	count;
	
	forrmat = ft_strdup(format);
	forrmat = ft_add_char(forrmat, '\0');
	count = 0;
	va_start(vl, format);
	while (num != 0)
	{
		num = start_printf(vl, &forrmat);
		count += num;
	}
	va_end(vl);
	return (count);
}

int		start_printf(va_list vl, char **format)
{
		int	count_symb;
		
		count_symb = 0;
	if (*(*format) != '\0' && *(*format) == '%' && (*format)[1] == '%')
	{
		count_symb += final_putchar((*format)[1]);//out %
		*format += 2;
	}
	else if (*(*format) == '%' && !((*format)[1]))
		return 0;
	else if (*(*format) != '\0' && *(*format) == '%' && (*format)[1])
		{
			(*format)++;
			count_symb += start_parce(vl, (*format));
			while (*(*format) != 'd' && *(*format) != 'i' && *(*format) != 'o' && *(*format) != 'u' && *(*format) != 'x'
		&& *(*format) != 'X' && *(*format) != 'f' && *(*format) != 'c' && *(*format) != 's' && *(*format) != 'p')
			(*format)++;
			(*format)++;
		}
	else if (*(*format) != '\0')
	{
		count_symb += final_putchar(*(*format));
		//count_symb++;
		(*format)++;
		//out text;
	}
	else
		return 0;
	return count_symb;
}


int		start_parce(va_list vl, char *format)
{
	t_flags		*flag;
	char		*buf;
	buf = (char *)malloc(sizeof(char *) * 1);
	buf[0] = '\0';
	flag = newflags(&flag);
	while (*format != 'd' && *format != 'i' && *format != 'o' && *format != 'u' && *format != 'x'
		&& *format != 'X' && *format != 'f' && *format != 'c' && *format != 's' && *format != 'p')
	{
		buf = ft_add_char(buf, *format);
		format++;
	}
	buf = ft_add_char(buf, *format);
	format++;
	return cont1_parce(vl, buf, &flag);
}

void	parce_flags(char *buf, t_flags **flag)
{
	size_t	i;
	
	i = 0;
	while (i < ft_strlen(buf))
	{
		if (buf[i] == '#')
			(*flag)->grid += 1;
		else if (buf[i] == '-')
			(*flag)->minus += 1;
		else if (buf[i] == '+')
			(*flag)->plus += 1;
		else if (buf[i] == ' ')
			(*flag)->space += 1;
		else if (buf[i] == 'l')
			(*flag)->l += 1;
		else if (buf[i] == 'h')
			(*flag)->h += 1;
		else if (buf[i] == 'L')
			(*flag)->lbig += 1;
		i++;
	}
	parce_flags2(buf, flag);
	return ;
}

void 	parce_flags2(char *buf, t_flags **flag)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(buf))
	{
		if (buf[0] == '0' || (buf[i] == '0' && (buf[i - 1] < '0' || buf[i - 1] > '9')))
		{
			(*flag)->zero = 1;
			i++;
		}
		else if (buf[i] >= '1' && buf[i] <= '9' && (*flag)->width == 0 && (*flag)->precision == -1)
		{
			(*flag)->width = ft_atoi(buf + i);
			i += ft_lennbr((*flag)->width);
		}
		else if (buf[i] == '.')
		{
			precision(buf, flag);
			i += ft_lennbr((*flag)->precision);
		}
		else
		{
			i++;
		}
	}
	return ;
}

void	precision(char *buf, t_flags **flag)
{
	size_t	i;

	i = 0;
	while (buf[i] != '.')
		i++;
	i++;
	(*flag)->precision = ft_atoi(buf + i);
	return ;
}

int		cont1_parce(va_list vl, char *buf, t_flags **flag)
{
	char	spec;

	spec = buf[ft_strlen(buf) - 1];
	printf("%c\n", spec);
	parce_flags(buf, flag);
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", (*flag)->grid, (*flag)->zero, (*flag)->minus, (*flag)->plus, (*flag)->space, (*flag)->l, (*flag)->lbig, (*flag)->h, (*flag)->width, (*flag)->precision);
	
	
	if (spec == 'd' || spec == 'i' || spec == 'o' || spec == 'u' || spec == 'x')
		return(lets_go_dioux(vl, flag, spec));
	else if (spec == 'X' || spec == 'f' || spec == 'c' || spec == 's' || spec == 'p')
		return(lets_go_Xfcsp(vl, flag, spec));
}

int		lets_go_dioux(va_list vl, t_flags **flag, char spec)
{
	if (spec == 'd')
		return final_putstr(ints(flag, va_arg(vl, int)));
	if (spec == 'o')
		return sw_o_flag(va_arg(vl, unsigned), *flag);
	
	
	if (spec == 'x')
		return sw_x_flag(va_arg(vl, unsigned), *flag);
}

int		lets_go_Xfcsp(va_list vl, t_flags **flag, char spec)
{
	if (spec == 's')
			return sw_s_flag(va_arg(vl, char*), *flag);
	if (spec == 'p')
			return sw_p_flag(va_arg(vl, void*), *flag);
}

t_flags	*newflags(t_flags **flag)
{
	*flag = malloc(sizeof(t_flags));
	(*flag)->grid = 0;
	(*flag)->zero = 0;
	(*flag)->minus = 0;
	(*flag)->plus = 0;
	(*flag)->space = 0;
	(*flag)->l = 0;
	(*flag)->lbig = 0;
	(*flag)->h = 0;
	(*flag)->width = 0;
	(*flag)->precision = -1;
	return *flag;
}

int main()
{
	int *a;
	a = NULL;
     ft_printf("%d,\t %d",1 , 1);
	 printf("\n%d,\t %d",1 , 1);
	//printf("%f", 0.56489465165498465412983441982449823498442398449283449823494842384423544982344);
    return (0);
}//\n%015.6d"