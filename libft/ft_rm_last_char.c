/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_last_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:05:31 by dvictor           #+#    #+#             */
/*   Updated: 2019/11/08 19:06:27 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rm_last_char(char *str)
{
	char	*newstr;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	newstr = malloc(sizeof(char *) * i);
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
	}
	free(str);
	return (newstr);
}
