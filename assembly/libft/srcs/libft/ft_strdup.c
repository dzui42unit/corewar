/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:45:54 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/05 13:24:38 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strcopy;
	char	*p;

	strcopy = (char*)malloc(sizeof(*strcopy) * (ft_strlen(s1) + 1));
	if (strcopy == NULL)
		return (NULL);
	p = strcopy;
	while (*s1 != '\0')
	{
		*strcopy = *s1;
		strcopy++;
		s1++;
	}
	*strcopy = '\0';
	return (p);
}
