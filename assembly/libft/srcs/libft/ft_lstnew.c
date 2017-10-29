/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:46:02 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 13:48:44 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (new_list)
	{
		if (content)
		{
			new_list->content = ft_memalloc(content_size);
			if (new_list->content)
				ft_memcpy(new_list->content, content, content_size);
			new_list->content_size = content_size;
		}
		else
		{
			new_list->content = NULL;
			new_list->content_size = 0;
		}
		new_list->next = NULL;
	}
	return (new_list);
}
