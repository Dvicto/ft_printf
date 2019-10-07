/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:57 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/12 16:38:58 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*stack;
	char	*need;
	size_t	i;
	size_t	fora;

	stack = (char *)haystack;
	need = (char *)needle;
	if (!*need)
		return (stack);
	fora = 0;
	i = ft_strlen(need);
	if (i > n && haystack)
		return (NULL);
	while (*stack && n - i >= fora)
	{
		if (ft_strncmp(stack, need, i) == 0)
			return (stack);
		stack++;
		fora++;
	}
	return (NULL);
}
