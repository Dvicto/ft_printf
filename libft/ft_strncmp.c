/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:38 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/05 18:55:05 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*str11;
	unsigned char	*str21;
	size_t			i;

	i = 0;
	str11 = (unsigned char *)str1;
	str21 = (unsigned char *)str2;
	if (n <= 0)
		return (0);
	while (str11[i] == str21[i] && str11[i] != '\0' &&
			str21[i] != '\0' && n != i)
		i++;
	if (n == i)
		return (str11[i - 1] - str21[i - 1]);
	return (str11[i] - str21[i]);
}
