/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:16 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:27:00 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	int		m;
	size_t	dlina;

	dlina = size + ft_strlen(src);
	if (dlina > ft_strlen(dest) + ft_strlen(src))
		dlina = ft_strlen(dest) + ft_strlen(src);
	m = (int)size - (int)ft_strlen(dest) - 1;
	if (m < 0)
		m = 0;
	dest = ft_strncat(dest, src, m);
	return (dlina);
}
