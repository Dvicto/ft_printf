/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:10:40 by dvictor           #+#    #+#             */
/*   Updated: 2019/10/15 15:14:02 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_add_char(char **buf, char c)
{
    char    *str;
    int     i;

    i = 0;
    if (*buf == '\0')
        str = (char *)ft_memalloc(2);
    else
    {
        str = (char *)ft_memalloc(ft_strlen(*buf) + 1);
        while (buf[i] != '\0')
        {
            str[i] = *buf[i];
            i++;
        }
    }
    str[i] = c;
    //free(buf);
    return (str);
}