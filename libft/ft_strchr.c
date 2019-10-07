/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:10:32 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:10:33 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buf;

	buf = (char *)s;
	while (*buf != c && *buf != '\0')
		buf++;
	if (*buf == '\0' && c == *buf)
		return (buf);
	if (*buf == '\0')
		return (NULL);
	return (buf);
}
