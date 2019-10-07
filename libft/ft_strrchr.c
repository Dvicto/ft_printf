/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:12:01 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:56:27 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strchr(s, c) != NULL)
	{
		while (*s != '\0')
		{
			if (*s == c)
				j = i;
			i++;
			s++;
		}
		if (c == '\0')
			return ((char *)s);
		while (i != j)
		{
			s--;
			i--;
		}
		return ((char *)s);
	}
	return (NULL);
}
