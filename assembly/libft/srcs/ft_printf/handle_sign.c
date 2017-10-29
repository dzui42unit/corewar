/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:22:09 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 16:22:30 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_handle_sign(char **fmt, t_format *tf, long arg)
{
	char	*t;

	if (tf->flags->show_sign)
	{
		t = ft_strdup(*fmt);
		ft_strdel(fmt);
		*fmt = ((int)arg >= 0) ? ft_strjoin("+", t) : ft_strjoin("-", t);
		ft_strdel(&t);
	}
	else if (arg < 0)
	{
		t = ft_strdup(*fmt);
		ft_strdel(fmt);
		*fmt = ft_strjoin("-", t);
		ft_strdel(&t);
	}
}
