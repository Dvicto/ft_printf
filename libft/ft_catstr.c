/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:49:38 by artem             #+#    #+#             */
/*   Updated: 2019/09/20 16:32:54 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_catstr(const char *s1, char *s2)
{
	char	*s;

	if (!s1 || *s1 == '\0')
	{
		s = ft_strnew(ft_strlen(s2) + 1);
		s = ft_strcpy(s, s2);
		return (s);
	}
	s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	s = ft_strcpy(s, s1);
	s = ft_strcpy(s + ft_strlen(s1), s2);
	s = s - ft_strlen(s1);
	s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (s);
}
