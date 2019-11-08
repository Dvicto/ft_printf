/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_u_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <nsheev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:46:15 by nsheev            #+#    #+#             */
/*   Updated: 2019/11/08 17:57:37 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		sw_ft_putnbr_u_h(unsigned short nb)
{
	if (nb / 10)
		sw_ft_putnbr_u_h(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	sw_ft_putnbr_u_hh(unsigned char nb)
{
	if (nb / 10)
		sw_ft_putnbr_u_hh(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	sw_ft_putnbr_u_l(unsigned long nb)
{
	if (nb / 10)
		sw_ft_putnbr_u_l(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	sw_ft_putnbr_u_ll(unsigned long long nb)
{
	if (nb / 10)
		sw_ft_putnbr_u_ll(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void		sw_ft_putnbr_u_cas(unsigned nb)
{
	if (nb / 10)
		sw_ft_putnbr_u_cas(nb / 10);
	ft_putchar(nb % 10 + 48);
}
