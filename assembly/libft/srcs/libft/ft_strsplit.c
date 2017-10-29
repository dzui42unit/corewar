/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:32:06 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/07 11:56:50 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_scount(char const *s, char c)
{
	int		counter;
	int		flag;

	counter = 0;
	flag = 1;
	while (*s != '\0')
	{
		if (*s == c)
			flag = 1;
		else if (flag == 1)
		{
			counter++;
			flag = 0;
		}
		s++;
	}
	return (counter);
}

static int	ft_lcount(char const *s, char c)
{
	int		counter;

	counter = 0;
	while (*s != c && *s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		l_count;
	int		w_count;

	w_count = 0;
	if (s == NULL)
		return (NULL);
	if ((split = (char**)malloc(sizeof(char*) * (ft_scount(s, c) + 1))) == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		l_count = ft_lcount(s, c);
		split[w_count] = (char*)malloc(sizeof(char) * (l_count + 1));
		if (split[w_count] == NULL)
			return (NULL);
		split[w_count] = ft_strncpy(split[w_count], s, l_count);
		split[w_count++][l_count] = '\0';
		s = s + l_count;
	}
	split[w_count] = 0;
	return (split);
}
