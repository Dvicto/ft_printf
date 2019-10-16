/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:57:27 by nsheev            #+#    #+#             */
/*   Updated: 2019/10/16 17:31:17 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_flags
{
	int				grid;//#
	int				zero;//"0"
	int				minus;//"-"
	int				plus;//"+"
	int				space;//" "
	int				l;//"l   /   ll"
	int				lbig;//"L"
	int				h;//" h     /   hh"
	int				width;
	int				precision;
}					t_flags;

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

int		sw_s_flag(char *s, t_flags *l)
{
	int		i;
	int		len;
	int		z;

	i = 0;
	len = 0;
	z = 0;
	len = ft_strlen(s);
	if (l->precision != -1 && len > l->precision)
		len = l->precision;
	if (l->minus == 0)
		while (l->width > len)
		{
			write(1, " ", 1);
			i++;
			l->width--;
		}
	while(len > 0)
	{
		write(1, &s[z], 1);
		z++;
		i++;
		len--;
		l->width--;
	}
	while (l->width > 0)
	{
		write(1, " ", 1);
		l->width--;
	}
	return (i);
}

int main()
{
	t_flags	*l;

	l = (t_flags *)malloc(sizeof(t_flags));
	l->grid = 0;
	l->precision = -1;
	l->zero = 0;
	l->width = 1;
	l->minus = 0;
	l->space = 0;
	l->plus = 0;
	sw_s_flag("common guys!", l);
	printf("end\n%1send\n", "common guys!");
	return (0);
}