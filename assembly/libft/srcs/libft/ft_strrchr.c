/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:41:29 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 13:00:15 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	*temp;

	temp = NULL;
	while (*src != '\0')
	{
		if (*src == (char)c)
			temp = (char*)src;
		src++;
	}
	if (*src == (char)c)
		return ((char*)src);
	return (temp);
}
