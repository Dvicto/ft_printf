/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:35 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:17:22 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	m;
	size_t	j;

	i = 0;
	j = 0;
	m = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && m != n)
	{
		dest[i] = src[j];
		m++;
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
