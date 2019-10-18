/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:08:34 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/18 12:22:14 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	int			len;
	char		*s;

	len = n;
	i = ft_lennbr(len);
	if (!(s = (char *)ft_memalloc((size_t) i + 1)))
		return (NULL);
	s[i] = '\0';
	i--;
	if (len < 0)
	{
		s[0] = '-';
		len = len * -1;
	}
	while (len >= 10)
	{
		s[i] = len % 10 + '0';
		len = len / 10;
		i--;
	}
	s[i] = len % 10 + '0';
	return (s);
}
