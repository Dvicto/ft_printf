/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:10:40 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/16 19:20:16 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_add_char(char *buf, char c)
{
    char    *str;
    int     i;

    i = 0;
    str = (char *)malloc(sizeof(char *) * (ft_strlen(buf) + 1));
    while (buf[i] != '\0')
        {
            str[i] = buf[i];
            i++;
        }
    str[i] = c;
    str[i + 1] = '\0';
    free(buf);
    return (str);
}