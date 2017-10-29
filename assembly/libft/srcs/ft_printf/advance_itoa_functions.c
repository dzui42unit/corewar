/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_itoa_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:47:04 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 15:49:19 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_ltoa(long value)
{
	int		i;
	long	t;
	char	*base_str;
	char	*str;

	i = 1;
	if (value < -9223372036854775807)
		return (ft_strdup("9223372036854775808"));
	t = value;
	if (value < 0)
		t = -t;
	base_str = "0123456789";
	while (value /= 10)
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	if (t == 0)
	{
		str[0] = '0';
		i--;
	}
	while (t && (str[--i] = base_str[t % 10]))
		t /= 10;
	return (str);
}

char	*pf_ltoa_base(long value, int base, char *base_str)
{
	unsigned long	t;
	unsigned long	u;
	int				i;
	char			*str;

	i = 1;
	t = value;
	u = value;
	while (u /= base)
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	if (t == 0)
	{
		str[0] = '0';
		i--;
	}
	while (t && (str[--i] = base_str[t % base]))
		t /= base;
	return (str);
}
