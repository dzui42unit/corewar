/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:41:07 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 12:57:34 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t siz)
{
	char		*destcpy;
	const char	*srccpy;
	size_t		sizcpy;
	size_t		destlen;

	destcpy = dest;
	srccpy = src;
	sizcpy = siz;
	while (*destcpy != '\0' && sizcpy-- != 0)
		destcpy++;
	destlen = destcpy - dest;
	sizcpy = siz - destlen;
	if (sizcpy == 0)
		return (destlen + ft_strlen(src));
	while (*srccpy != '\0')
	{
		if (sizcpy != 1)
		{
			*destcpy++ = *srccpy;
			sizcpy--;
		}
		srccpy++;
	}
	*destcpy = '\0';
	return (destlen + (srccpy - src));
}
