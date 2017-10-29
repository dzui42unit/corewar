/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:31:20 by ozabara           #+#    #+#             */
/*   Updated: 2016/11/24 17:05:48 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)memptr;
	while (num != 0)
	{
		*ptr = (unsigned char)val;
		ptr++;
		num--;
	}
	return (memptr);
}
