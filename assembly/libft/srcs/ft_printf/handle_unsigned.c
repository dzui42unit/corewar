/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:25:51 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 17:48:27 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_print_unsigned(char **fmt, t_format *tf, unsigned long arg)
{
	char	*t;
	char	*p;
	char	*k;

	*fmt = pf_ltoa_base(arg, 10, "0123456789");
	pf_handle_precision_1(fmt, tf, arg, &k);
	pf_handle_precision_2(*fmt, tf, &k, &p);
	pf_handle_width(*fmt, tf, &k, &p);
	t = (ft_strlen(p)) ? ft_strjoin(p, *fmt) : ft_strjoin(*fmt, p);
	ft_strdel(&p);
	ft_strdel(fmt);
	if (tf->flags->show_sign && ft_strlen(k) > 0)
	{
		p = ft_strsub(k, 1, ft_strlen(k) - 1);
		ft_strdel(&k);
		k = ft_strdup(p);
		ft_strdel(&p);
	}
	*fmt = (tf->flags->justify_left) ? ft_strjoin(t, k) : ft_strjoin(k, t);
	ft_strdel(&t);
	ft_strdel(&k);
}

void		pf_handle_unsigned(char **fmt, t_format *tf, void *arg)
{
	if (tf->length == 1 && tf->type != 10)
		pf_print_unsigned(fmt, tf, (unsigned char)arg);
	else if (tf->length == 2 && tf->type != 10)
		pf_print_unsigned(fmt, tf, (unsigned short)arg);
	else if (tf->length == 3 || tf->length == 4 || tf->type == 10)
		pf_print_unsigned(fmt, tf, (unsigned long)arg);
	else if (tf->length == 5)
		pf_print_unsigned(fmt, tf, (unsigned long)arg);
	else if (tf->length == 6)
		pf_print_unsigned(fmt, tf, (unsigned long)arg);
	else
		pf_print_unsigned(fmt, tf, (unsigned int)arg);
}
