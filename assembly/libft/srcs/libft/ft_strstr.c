/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:41:39 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 15:18:57 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *str)
{
	size_t	len;

	if (!*str)
		return (char*)(src);
	len = ft_strlen(str);
	while (*src != '\0')
	{
		if (!ft_memcmp(src, str, len))
			return ((char*)src);
		src++;
	}
	return (NULL);
}
