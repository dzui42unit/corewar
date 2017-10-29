/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:56:11 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/07 12:00:56 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*elem;
	t_list		*first;

	if (lst == NULL || f == NULL)
		return (NULL);
	first = ft_lstnew(lst->content, lst->content_size);
	if (first == NULL)
		return (NULL);
	first = (*f)(first);
	elem = first;
	while (lst->next != NULL)
	{
		lst = lst->next;
		elem->next = ft_lstnew(lst->content, lst->content_size);
		if (elem->next == NULL)
			return (NULL);
		elem->next = (*f)(elem->next);
		elem = elem->next;
	}
	return (first);
}
