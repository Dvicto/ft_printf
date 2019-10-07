/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:12:27 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/06 15:43:48 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	j = 0;
	k = 0;
	if (!(s))
		return (NULL);
	i = ft_strlentrim(s);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	ft_strclr(str);
	if (i == 0)
		return (str);
	i = ft_strlen(s);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	while (j != i)
		str[k++] = s[j++];
	str[k] = '\0';
	return (str);
}
