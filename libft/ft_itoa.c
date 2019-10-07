/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:08:34 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 19:42:28 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	long int	len;
	char		*s;

	len = n;
	i = ft_lennbr(len);
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
