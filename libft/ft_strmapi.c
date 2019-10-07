/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:31 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/06 15:38:45 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	unsigned int	j;
	char			*str;

	if (!(s))
		return (NULL);
	i = 0;
	j = 0;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*s)
	{
		str[i] = f(j, *s);
		s++;
		i++;
		j++;
	}
	return (str);
}
