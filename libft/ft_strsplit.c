/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:12:08 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/12 15:03:12 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] == c && s[j] != '\0')
		j++;
	while (s[j] != '\0')
	{
		if (s[j] != c && s[j + 1] == c)
			i++;
		j++;
	}
	if (s[j] == '\0' && s[j - 1] != c)
		i++;
	return (i);
}

static size_t	ft_memword(const char *s, char c, size_t i)
{
	size_t	n;

	n = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		n++;
	}
	return (n);
}

static char		*ft_word(const char *s, char c, size_t *i)
{
	char	*str;
	size_t	j;

	j = 0;
	if (!(str = (char *)ft_memalloc(ft_memword(s, c, *i) + 1)))
		return (NULL);
	while (s[*i] != c && s[*i] != '\0')
	{
		str[j] = s[*i];
		*i = *i + 1;
		j++;
	}
	while (s[*i] == c && s[*i] != '\0')
		*i = *i + 1;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**str;

	if (!(s))
		return (NULL);
	i = 0;
	j = 0;
	words = ft_words(s, c);
	if (!(str = (char **)malloc(sizeof(str) * words + 1)))
		return (NULL);
	while (s[i] == c && s[i] != '\0')
		i++;
	while (j < words && s[i] != '\0')
	{
		str[j] = ft_word(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
