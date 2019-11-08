/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_i_norme_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:05:59 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/08 18:21:29 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				sw_length_i(int a)
{
	int			i;

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

void			sw_ft_putnbr_i_hh(char nb)
{
	if (nb == -128)
	{
		write(1, "128", 3);
		return ;
	}
	if (nb < 0)
		nb = nb * (-1);
	if (nb / 10)
		sw_ft_putnbr_i_hh(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int				sw_length_hh(char a)
{
	int			i;

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

void			sw_ft_putnbr_i_h(short nb)
{
	if (nb == -32768)
	{
		write(1, "32768", 5);
		return ;
	}
	if (nb < 0)
		nb = nb * (-1);
	if (nb / 10)
		sw_ft_putnbr_i_h(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int				sw_length_h(short a)
{
	int			i;

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
