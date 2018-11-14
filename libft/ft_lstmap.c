/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:34:28 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/21 07:47:52 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *tmp;
	t_list *new_list;

	if (lst == NULL || !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (first)
		{
			if (!(new_list->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			new_list = new_list->next;
		}
		else
		{
			if (!(new_list = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			first = new_list;
		}
		lst = lst->next;
	}
	return (first);
}
