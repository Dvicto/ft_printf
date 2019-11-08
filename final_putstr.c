/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:16:29 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/08 16:19:04 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			final_putstr(char *str)
{
	int		i;

	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

int			final_putchar(char c)
{
	if (c)
		write(1, &c, 1);
	return (1);
}
