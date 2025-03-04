/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_i_norme_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:40:40 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/08 18:19:14 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		sw_ft_putnbr_l(long nb)
{
	if (nb == LONG_MIN)
	{
		write(1, "9223372036854775808", 19);
		return ;
	}
	if (nb < 0)
		nb = nb * (-1);
	if (nb / 10)
		sw_ft_putnbr_l(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int			sw_length_l(long a)
{
	int		i;

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

void		sw_ft_putnbr_ll(long long nb)
{
	if (nb == LLONG_MIN)
	{
		write(1, "9223372036854775808", 19);
		return ;
	}
	if (nb < 0)
		nb = nb * (-1);
	if (nb / 10)
		sw_ft_putnbr_ll(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int			sw_length_ll(long long a)
{
	int		i;

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

void		sw_ft_putnbr_i(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (nb < 0)
		nb = nb * (-1);
	if (nb / 10)
		sw_ft_putnbr_i(nb / 10);
	ft_putchar(nb % 10 + 48);
}
