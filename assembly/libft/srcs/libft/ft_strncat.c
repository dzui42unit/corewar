/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:40:54 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 12:48:58 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*destcpy;

	destcpy = dest;
	while (*destcpy != '\0')
		destcpy++;
	while (*src != '\0' && n > 0)
	{
		*destcpy = *src;
		destcpy++;
		src++;
		n--;
	}
	*destcpy = '\0';
	return (dest);
}
