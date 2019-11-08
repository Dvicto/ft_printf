/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:17:15 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/08 16:17:16 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	color(char **format)
{
	int len;

	if (!ft_strncmp(*format, "{red}", (len = 5)))
		final_putstr(RED);
	else if (!ft_strncmp(*format, "{green}", (len = 7)))
		final_putstr(GREEN);
	else if (!ft_strncmp(*format, "{black}", (len = 7)))
		final_putstr(BLACK);
	else if (!ft_strncmp(*format, "{white}", (len = 7)))
		final_putstr(WHITE);
	else if (!ft_strncmp(*format, "{yellow}", (len = 8)))
		final_putstr(YELLOW);
	else if (!ft_strncmp(*format, "{blue}", (len = 6)))
		final_putstr(BLUE);
	else if (!ft_strncmp(*format, "{purple}", (len = 8)))
		final_putstr(PURPLE);
	else if (!ft_strncmp(*format, "{cyan}", (len = 6)))
		final_putstr(CYAN);
	else if (!ft_strncmp(*format, "{bold}", (len = 6)))
		final_putstr(BOLD);
	else if (!ft_strncmp(*format, "{eoc}", (len = 5)))
		final_putstr(RESET);
	else
		(len = 0);
	(*format) += (len);
}
