/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:25:10 by ozabara           #+#    #+#             */
/*   Updated: 2017/06/01 15:20:38 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;

	if (s)
	{
		str = (char*)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			ptr = str;
			while (len-- > 0 && *s != '\0')
				*ptr++ = s[start++];
			*ptr = '\0';
			return (str);
		}
		else
			return (NULL);
	}
	return (NULL);
}
