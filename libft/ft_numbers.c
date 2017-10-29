/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 13:22:14 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 16:25:55 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_numbers_base(t_flags *fl, char conv)
{
	int base;
	int nb_case;

	base = -1;
	nb_case = 0;
	ft_define_base(conv, &base, &nb_case, fl);
	if (fl->minus && base == 16)
		ft_minus_base_16(fl, base, nb_case);
	if (!fl->minus && base == 16)
		ft_no_minus_base_16(fl, base, nb_case);
	if (fl->minus && base == 8)
		ft_minus_base_8(fl, base, nb_case);
	if (!fl->minus && base == 8)
		ft_no_minus_base_8(fl, base, nb_case);
	if (!fl->minus && base == 10)
		ft_no_minus_base_10(fl, base, nb_case);
	if (fl->minus && base == 10)
		ft_minus_base_10(fl, base, nb_case);
}

void	ft_define_base(char conv, int *base, int *nb_case, t_flags *fl)
{
	if (conv == 'x' || conv == 'p')
	{
		if (conv == 'p')
			fl->hash = 1;
		*base = 16;
	}
	if (conv == 'X')
	{
		*nb_case = 1;
		*base = 16;
	}
	if (conv == 'o' || conv == 'O')
		*base = 8;
	if (conv == 'u' || conv == 'U')
		*base = 10;
	if (conv == 'd' || conv == 'i' || conv == 'D')
		*base = 10;
}

void	ft_set_char(t_flags *fl, char *ch)
{
	*ch = ' ';
	if (fl->zero)
		*ch = '0';
}
