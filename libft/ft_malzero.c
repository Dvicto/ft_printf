/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:09:09 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/18 20:12:50 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_malzero(size_t i)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * i);
	i--;
	while (i != 0)
	{
		str[i] = '\0';
		i--;
	}
	str[i] = '\0';
	return (str);
}
