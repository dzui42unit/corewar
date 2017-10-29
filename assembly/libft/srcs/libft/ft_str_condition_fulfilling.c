/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_condition_fulfilling.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:05:22 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:05:24 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_condition_fulfilling(const char *str, int (*f)())
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((*f)(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
