/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:10:26 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 13:11:18 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memtp;

	memtp = (void*)malloc(sizeof(void) * size);
	if (memtp == NULL)
		return (NULL);
	else
		return (ft_memset(memtp, 0, size));
}
