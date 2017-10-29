/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:40:44 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 12:43:36 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*destcpy;

	destcpy = dest;
	while (*destcpy != '\0')
		destcpy++;
	while (*src != '\0')
	{
		*destcpy = *src;
		destcpy++;
		src++;
	}
	*destcpy = '\0';
	return (dest);
}
