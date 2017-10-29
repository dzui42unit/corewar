/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:20:00 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 16:21:00 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_handle_precision_2(char *fmt, t_format *tf, char **k, char **p)
{
	*k = 0;
	*p = 0;
	if (tf->precision_value > (int)ft_strlen(fmt))
	{
		*p = ft_strnew(tf->precision_value - ft_strlen(fmt));
		*p = ft_memset(*p, '0', tf->precision_value - ft_strlen(fmt));
	}
	if (!(*p))
		*p = ft_strdup("");
}

void		pf_handle_precision_1(char **fmt, t_format *tf, unsigned long arg,
									char **k)
{
	int		length;

	length = ft_strlen(*fmt);
	if (tf->precision_flag && tf->precision_value < length && !arg)
	{
		length = (tf->precision_value < 0) ? 0 : tf->precision_value;
		*k = ft_strsub(*fmt, ft_strlen(*fmt) - length, length);
		ft_strdel(fmt);
		*fmt = ft_strdup(*k);
		ft_strdel(k);
	}
}
