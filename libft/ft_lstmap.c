/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:09:01 by dvictor           #+#    #+#             */
/*   Updated: 2019/09/06 15:55:19 by dvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*listt;

	if (!(lst))
		return (NULL);
	if (!(list = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		free(list);
		return (NULL);
	}
	list = f(lst);
	lst = lst->next;
	listt = list;
	while (lst != NULL)
	{
		list->next = f(lst);
		list = list->next;
		lst = lst->next;
	}
	return (listt);
}
