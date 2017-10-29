/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:16:53 by ozabara           #+#    #+#             */
/*   Updated: 2016/11/24 17:13:00 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char*)dst;
	s = (char*)src;
	if (s < d)
	{
		d = d + len - 1;
		s = s + len - 1;
		while (len != 0)
		{
			*d-- = *s--;
			len--;
		}
	}
	else
	{
		while (len != 0)
		{
			*d++ = *s++;
			len--;
		}
	}
	return (dst);
}
