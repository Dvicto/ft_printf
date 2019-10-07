/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:10:46 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:10:46 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*str11;
	unsigned char	*str21;

	str11 = (unsigned char *)str1;
	str21 = (unsigned char *)str2;
	while (*str11 == *str21 && *str11 != '\0' && *str21 != '\0')
	{
		str11++;
		str21++;
	}
	return (*str11 - *str21);
}
