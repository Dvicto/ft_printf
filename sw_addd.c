/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_addd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:49:32 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/11 20:02:08 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sw_000(t_flags *l, int *i)
{
	write(1, "0", 1);
	l->width--;
	(*i)++;
}

int		qwerty(char **buf, t_flags **flag)
{
	if (*buf)
		free(*buf);
	if (*flag)
		free(*flag);
	return (0);
}
