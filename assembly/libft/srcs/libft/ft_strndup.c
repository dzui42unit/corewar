/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:07:56 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:07:57 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t nbr)
{
	size_t	i;
	char	*out;

	if (!(out = ft_strnew(nbr)))
		return (NULL);
	i = 0;
	while (nbr && s1[i])
	{
		out[i] = s1[i];
		i++;
		nbr--;
	}
	out[i] = '\0';
	return (out);
}
