/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:09:24 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:09:25 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	unsigned char	cc;

	cc = (unsigned char)c;
	ss = (unsigned char *)s;
	while (n)
	{
		if (*ss == cc)
			return (ss);
		ss++;
		n--;
	}
	return (NULL);
}
