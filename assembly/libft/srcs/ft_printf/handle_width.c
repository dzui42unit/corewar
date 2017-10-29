/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:26:56 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 16:28:58 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_handle_width(char *fmt, t_format *tf, char **k, char **p)
{
	int		i;
	int		c;

	if (tf->min_width > tf->precision_value && tf->min_width > 0)
	{
		c = (tf->flags->add_zeros && !tf->flags->justify_left &&
				tf->precision_value == -1) ? '0' : ' ';
		i = tf->min_width - (ft_strlen(fmt) + ft_strlen(*p));
		if (i > 0)
		{
			*k = ft_strnew(i);
			*k = ft_memset(*k, c, i);
		}
	}
	if (!(*k))
		*k = ft_strdup("");
}
