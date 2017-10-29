/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:07:09 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 19:07:16 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_get_index(intmax_t number, int base)
{
	int index;

	index = (int)(number % base);
	if (index < 0)
		index *= -1;
	return (index);
}

void			ft_set_minus(char *res, int flag, intmax_t number, int *nb)
{
	if (number < 0)
	{
		flag = 1;
		(*nb)++;
	}
	if (flag)
		res[0] = '-';
	res[(*nb)--] = '\0';
}

int				ft_count_digs_signed(intmax_t number, int nb, int base)
{
	while (number != 0)
	{
		nb++;
		number /= base;
	}
	return (nb);
}

int				ft_count_digs_unsigned(uintmax_t number, int nb, int base)
{
	while (number != 0)
	{
		nb++;
		number /= base;
	}
	return (nb);
}
