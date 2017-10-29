/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:38:31 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 12:38:56 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*destcpy;

	destcpy = dest;
	while (*src != '\0')
	{
		*destcpy = *src;
		destcpy++;
		src++;
	}
	*destcpy = '\0';
	return (dest);
}
