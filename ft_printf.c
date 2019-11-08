/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:16:20 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/08 16:21:34 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		vl;
	char		*forrmat;
	char		*s;
	int			num;
	int			count;

	num = 0;
	forrmat = ft_strdup(format);
	s = forrmat;
	count = 0;
	va_start(vl, format);
	while (num != 0 || *forrmat != '\0')
	{
		num = start_printf(vl, &forrmat, 0);
		count += num;
	}
	free(s);
	va_end(vl);
	return (count);
}

void			precision(char *buf, t_flags **flag)
{
	size_t		i;

	i = 0;
	while (buf[i] != '.')
		i++;
	i++;
	(*flag)->precision = ft_atoi(buf + i);
	return ;
}
