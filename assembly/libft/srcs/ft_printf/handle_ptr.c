/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:21:20 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 16:21:42 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_subprint_ptr(t_format *tf, char **t, char **k, char **p)
{
	if (ft_strlen(*k) > 1)
		*t = ft_strsub(*k, 2, ft_strlen(*k) - 2);
	else
		*t = ft_strdup("");
	ft_strdel(k);
	if (tf->flags->add_zeros && !(tf->flags->justify_left) &&
			tf->precision_value == -1)
	{
		*k = ft_strdup(*p);
		ft_strdel(p);
		*p = ft_strdup(*t);
		ft_strdel(t);
		*t = ft_strdup(*k);
		ft_strdel(k);
	}
}

void		pf_handle_ptr(char **fmt, t_format *tf, void *arg)
{
	char	*t;
	char	*p;
	char	*k;

	if (tf->type == 1)
		*fmt = pf_ltoa_base((unsigned long)arg, 16, "0123456789abcdef");
	else
		*fmt = pf_ltoa_base((unsigned long)arg, 16, "0123456789ABCDEF");
	pf_handle_precision_1(fmt, tf, (unsigned long)arg, &k);
	pf_handle_precision_2(*fmt, tf, &k, &p);
	pf_handle_width(*fmt, tf, &k, &p);
	pf_subprint_ptr(tf, &t, &k, &p);
	k = (tf->type == 1) ? ft_strjoin("0x", p) : ft_strjoin("0X", p);
	ft_strdel(&p);
	p = ft_strjoin(k, *fmt);
	ft_strdel(fmt);
	*fmt = (tf->flags->justify_left) ? ft_strjoin(p, t) : ft_strjoin(t, p);
	ft_strdel(&p);
	ft_strdel(&t);
	ft_strdel(&k);
}
