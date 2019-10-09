/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:08:34 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/09 17:50:47 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_llitoa(long long int len)
{
	int			i;
	char		*s;

	i = ft_llennbr(len);
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
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
