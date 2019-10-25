/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_i_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:24:25 by swedde            #+#    #+#             */
/*   Updated: 2019/10/25 15:01:37 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "printf.h"

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

void 		ft_putchar(char c)
{
  write(1 , &c, 1);
}

void		ft_putnbr(long long nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb / 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int			sw_length(long long a)
{
	int i;

	if (!a)
		return (1);
	i = 0;
	while (a)
	{
		i++;
		a /= 10;
	}
	return (i);
}

static void	sw_check_sign(int *len, int *i, t_flags *l, long long a)
{
	if (a < 0)
	{
		write(1, "-", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
	if (l->plus && a > -1)
	{
		write(1, "+", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
	if (l->space && !l->plus && a > -1)
	{
		write(1, " ", 1);
		(*i)++;
		(*len)--;
		l->width--;
	}
}

static int	sw_if_minus(int *len, t_flags *l, long long a)
{
	int		i;

	i = 0;
	sw_check_sign(len, &i, l, a);
	while (l->precision > sw_length(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
		l->width--;
	}
	ft_putnbr(a);
	i += sw_length(a);
	l->width -= sw_length(a);
	while (l->width > 0)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	return (i);
}

static int	sw_if_zero(int *len, t_flags *l, long long a)
{
	int		i;

	i = 0;
	sw_check_sign(len, &i, l, a);
	while (l->width > *len)
	{
		write(1, "0", 1);
		i++;
		l->width--;
	}
	ft_putnbr(a);
	i += sw_length(a);
	return (i);
}

static int	sw_if_else(int *len, t_flags *l, long long a)
{
	int		i;

	i = 0;
	while (l->width > *len)
	{
		write(1, " ", 1);
		i++;
		l->width--;
	}
	sw_check_sign(len, &i, l, a);
	while (l->precision > sw_length(a))
	{
		write(1, "0", 1);
		i++;
		l->precision--;
	}
	ft_putnbr(a);
	i += sw_length(a);
	return (i);
}

int			sw_i_flag(long long a, t_flags *l)
{
	int		len;

	len = sw_length(a);
	if (l->minus || l->precision > -1)
		l->zero = 0;
	if (l->precision > len)
		len = l->precision;
	if (a < 0 || l->plus || l->space)
		len++;
	if (l->minus)
		return (sw_if_minus(&len, l, a));
	else if (l->zero)
		return (sw_if_zero(&len, l, a));
	else
		return (sw_if_else(&len, l, a));		
}
/*
int main()
{
	long long a = 8712691648736;
	t_flags *l;

	l = (t_flags *)malloc(sizeof(t_flags));
	l->grid = 0;
	l->precision = -1;
	l->zero = 1;
	l->width = 25;
	l->minus = 0;
	l->space = 0;
	l->plus = 1;

	sw_i_flag(a, l);
	printf("end\n%+025lliend\n", a);
	free(l);
	return (0);
}*/