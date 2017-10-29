/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:28:47 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/05 13:33:25 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	unsigned char			uc;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	uc = (unsigned char)c;
	while (n != 0)
	{
		*d = *s;
		d++;
		if (*s == uc)
		{
			return ((void*)d);
		}
		s++;
		n--;
	}
	return (NULL);
}
