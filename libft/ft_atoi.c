/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:07:47 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/06 17:04:51 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(unsigned long int n, int fl)
{
	if ((n > 2147483647) && (fl == 1))
		return (-1);
	else if (n > 2147483648)
		return (0);
	else
		return (1);
}

int			ft_atoi(const char *nptr)
{
	unsigned long int		i;
	unsigned long int		n;
	int						fl;

	fl = 1;
	i = 0;
	n = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9 && nptr[i] != '\0')
		|| nptr[i] == 32)
		i++;
	fl = ((nptr[i] == '-') ? -1 : fl);
	i = ((nptr[i] == '-') ? i + 1 : i);
	fl = ((nptr[i] == '+') && fl == -1 ? 0 : fl);
	if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0')
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (fl * n);
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	if (checker(n, fl) != 1)
		return (checker(n, fl));
	return (fl * n);
}
