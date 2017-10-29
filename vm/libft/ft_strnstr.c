/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:28:32 by dzui              #+#    #+#             */
/*   Updated: 2016/11/22 16:47:00 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	len = ft_strlen(to_find);
	len--;
	if (!(*to_find))
		return ((char *)(str));
	i = 0;
	j = 0;
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == to_find[j])
		{
			if (j == len)
				return ((char *)(str + i - len));
			j++;
		}
		else
			j = 0;
		i++;
	}
	return (NULL);
}
