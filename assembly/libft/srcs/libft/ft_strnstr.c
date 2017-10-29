/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:41:49 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 13:05:15 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *str, size_t n)
{
	size_t	len;

	len = ft_strlen(str);
	while (*src != '\0' && len <= n)
	{
		if (!ft_memcmp(src, str, len))
			return ((char*)src);
		src++;
		n--;
	}
	return (NULL);
}
