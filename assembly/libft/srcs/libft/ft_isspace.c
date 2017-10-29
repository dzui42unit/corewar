/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:03:45 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:03:46 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	return ((unsigned char)c == 32 || (unsigned char)c == '\t'
			|| (unsigned char)c == '\n' || (unsigned char)c == '\v'
			|| (unsigned char)c == '\f' || (unsigned char)c == '\r');
}
