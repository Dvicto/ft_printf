/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:12:14 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/06 16:28:57 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;
	char	*stack;
	char	*need;

	stack = (char *)haystack;
	need = (char *)needle;
	if (!(*need))
		return (stack);
	n = ft_strlen(need);
	while (*stack)
	{
		if (ft_strncmp(stack, need, n) == 0)
			return (stack);
		stack++;
	}
	return (NULL);
}
