/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:41 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:17:06 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*srcc;

	srcc = (char *)src;
	i = 0;
	while (i < n && srcc[i] != '\0')
	{
		dest[i] = srcc[i];
		i++;
	}
	if (srcc[i] == '\0')
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
		return (dest);
	}
	return (dest);
}
