/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlentrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:22 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:48:28 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlentrim(const char *s)
{
	int	j;

	j = (int)ft_strlen(s);
	j--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s++;
		j--;
	}
	if (j <= 0)
		return (0);
	return ((size_t)j + 1);
}
