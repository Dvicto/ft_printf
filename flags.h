/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swedde <swedde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:20:03 by swedde            #+#    #+#             */
/*   Updated: 2019/10/21 21:40:22 by swedde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

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

// end delete

# include <stdint.h>

int		sw_o_flag(unsigned a, t_flags *l);
int		sw_p_flag(void *a, t_flags *l);
int		sw_s_flag(char *s, t_flags *l);
int		sw_x_flag(unsigned a, t_flags *l);
void	len_print_hex(unsigned a, unsigned base, int *k);
void	print_hex(unsigned a, unsigned base);

#endif