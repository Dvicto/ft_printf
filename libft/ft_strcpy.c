/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:10:49 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:48:48 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	char	*srcc;

	i = 0;
	srcc = (char *)src;
	while (srcc[i] != '\0')
	{
		dest[i] = srcc[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
