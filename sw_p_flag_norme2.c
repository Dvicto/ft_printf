/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_p_flag_norme2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:12:42 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/11 18:47:52 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	sw_p_norme5(int *i, int *n, t_flags *l)
{
	write(1, "0x0", (*n));
	(*i) = (*n);
	while (l->precision - 1 > 0)
	{
		write(1, "0", 1);
		(*i)++;
		l->precision--;
	}
	while (l->width - (*n) > 0)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
}

static	void	sw_p_norme6(int *i, int *n, t_flags *l)
{
	while (l->width - (*n) > 0)
	{
		write(1, " ", 1);
		(*i)++;
		l->width--;
	}
	write(1, "0x0", (*n));
	(*i) += (*n);
	while (l->precision - 1 > 0)
	{
		write(1, "0", 1);
		(*i)++;
		l->precision--;
	}
}

int				if_p_null(t_flags *l)
{
	int			n;
	int			i;

	i = 0;
	if (l->precision == 0)
		n = 2;
	else
		n = 3;
	if (l->minus)
		sw_p_norme5(&i, &n, l);
	else
		sw_p_norme6(&i, &n, l);
	return (i);
}
