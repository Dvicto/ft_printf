/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:16:08 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/29 14:11:47 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int				start_printf(va_list vl, char **format, int count_symb)
{
	if (*(*format) != '\0' && *(*format) == '%' && (*format)[1] == '%')
	{
		count_symb += final_putchar((*format)[1]);
		*format += 2;
	}
	else if (*(*format) == '%' && !((*format)[1]))
		return (0);
	else if (*(*format) != '\0' && *(*format) == '%' && (*format)[1])
	{
		(*format)++;
		count_symb += start_parce(vl, format);
	}
	else if (*(*format) != '\0')
	{
		count_symb += final_putchar(*(*format));
		(*format)++;
	}
	else
		return (0);
	return (count_symb);
}

int				start_parce(va_list vl, char **format)
{
	t_flags		*flag;
	char		*buf;

	buf = (char *)malloc(sizeof(char *) * 1);
	buf[0] = '\0';
	flag = newflags(&flag);
	while (**format != 'd' && **format != 'i' && **format != 'o'
		&& **format != 'u' && **format != 'x' && **format != '%'
		&& **format != 'X' && **format != 'f'
		&& **format != 'c' && **format != 's' && **format != 'p')
	{
		buf = ft_add_char(buf, **format);
		(*format)++;
	}
	buf = ft_add_char(buf, **format);
	(*format)++;
	return (cont1_parce(vl, buf, &flag));
}

void			parce_flags(char *buf, t_flags **flag)
{
	size_t		i;

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

void			parce_flags2(char *buf, t_flags **flag)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(buf))
	{
		if (buf[0] == '0' || (buf[i] == '0' &&
		(buf[i - 1] < '0' || buf[i - 1] > '9')))
		{
			(*flag)->zero = 1;
			i++;
		}
		if (buf[i] >= '1' && buf[i] <= '9' && (*flag)->width == 0
			&& (*flag)->precision == -1)
		{
			(*flag)->width = ft_atoi(buf + i);
			i += ft_lennbr((*flag)->width);
		}
		if (buf[i] == '.')
		{
			precision(buf, flag);
			i += ft_lennbr((*flag)->precision);
		}
		else
			i++;
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

	spec = buf[ft_strlen(buf) - 2];
	parce_flags(buf, flag);
	//printf("%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n", (*flag)->grid, (*flag)->zero, (*flag)->minus, (*flag)->plus, (*flag)->space, (*flag)->l, (*flag)->lbig, (*flag)->h, (*flag)->width, (*flag)->precision);
	if (spec == 'd' || spec == 'i' || spec == 'o' || spec == 'u' || spec == 'x'
			|| spec == 'X')
		return (lets_go_dioux(vl, flag, spec));
	if (spec == 'f' || spec == 'c' || spec == 's' || spec == 'p')
		return (lets_go_fcsp(vl, flag, spec));
	if (spec == '%')
		return (c_flag('%', *flag));
	return (0);
}
