/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:10:33 by ozabara           #+#    #+#             */
/*   Updated: 2016/11/24 17:21:27 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *memptr, size_t num)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)memptr;
	while (num != 0)
	{
		*ptr = '\0';
		ptr++;
		num--;
	}
}
