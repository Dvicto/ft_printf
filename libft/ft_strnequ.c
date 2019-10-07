/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:50 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/06 15:41:14 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!(s1) || !(s2))
		return (0);
	i = 1;
	if (n == 0)
		return (1);
	if (ft_strlen(s1) < n)
		return (ft_strequ(s1, s2));
	while (i != n)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		i++;
	}
	if (*s1 == *s2)
		return (1);
	return (0);
}
