/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strn_condition_fulfilling.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:06:53 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:06:54 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strn_condition_fulfilling(const char *str, int (*f)(), size_t nbr)
{
	int	i;

	i = 0;
	while (nbr && str[i] != '\0')
	{
		if ((*f)(str[i]) == 1)
			return (1);
		i++;
		nbr--;
	}
	return (0);
}
