/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:22:52 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 16:23:14 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_handle_space(char **fmt, t_format *tf, char *k)
{
	char	*t;
	char	*p;

	if (tf->flags->add_space_if_no_sign &&
			!(tf->flags->show_sign) && **fmt != '-')
	{
		if (ft_strlen(k) == 0)
		{
			p = ft_strdup(" ");
			t = ft_strdup(*fmt);
			ft_strdel(fmt);
			*fmt = ft_strjoin(p, t);
			ft_strdel(&p);
			ft_strdel(&t);
		}
	}
}
