/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:40:33 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 12:41:34 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*destcpy;

	destcpy = dest;
	while (*src != '\0' && n > 0)
	{
		*destcpy = *src;
		n--;
		destcpy++;
		src++;
	}
	while (n > 0)
	{
		*destcpy = '\0';
		n--;
		destcpy++;
	}
	return (dest);
}
