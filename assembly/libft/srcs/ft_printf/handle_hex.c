/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:13:19 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 17:43:25 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_subprint_hex(t_format *tf, char **t, char **k, char **p)
{
	*t = (ft_strlen(*k) > 1) ? ft_strsub(*k, 2, ft_strlen(*k) - 2) :
			ft_strdup("");
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
	*k = (tf->type == 11) ? ft_strjoin("0x", *p) : ft_strjoin("0X", *p);
	ft_strdel(p);
	return (1);
}

static void	pf_print_hex(char **fmt, t_format *tf, unsigned long arg)
{
	char	*t;
	char	*p;
	char	*k;

	*fmt = (tf->type == 11) ? pf_ltoa_base(arg, 16, "0123456789abcdef") :
								pf_ltoa_base(arg, 16, "0123456789ABCDEF");
	pf_handle_precision_1(fmt, tf, arg, &k);
	pf_handle_precision_2(*fmt, tf, &k, &p);
	pf_handle_width(*fmt, tf, &k, &p);
	if (tf->flags->alter_form && arg && pf_subprint_hex(tf, &t, &k, &p))
	{
		p = ft_strjoin(k, *fmt);
		ft_strdel(fmt);
		*fmt = (tf->flags->justify_left) ? ft_strjoin(p, t) : ft_strjoin(t, p);
	}
	else
	{
		t = (ft_strlen(p)) ? ft_strjoin(p, *fmt) : ft_strjoin(*fmt, p);
		ft_strdel(fmt);
		*fmt = tf->flags->justify_left ? ft_strjoin(t, k) : ft_strjoin(k, t);
	}
	ft_strdel(&p);
	ft_strdel(&t);
	ft_strdel(&k);
}

void		pf_handle_hex(char **fmt, t_format *tf, void *arg)
{
	if (tf->length == 1)
		pf_print_hex(fmt, tf, (unsigned char)arg);
	else if (tf->length == 2)
		pf_print_hex(fmt, tf, (unsigned short)arg);
	else if (tf->length == 3 || tf->length == 4)
		pf_print_hex(fmt, tf, (unsigned long)arg);
	else if (tf->length == 5)
		pf_print_hex(fmt, tf, (unsigned long)arg);
	else if (tf->length == 6)
		pf_print_hex(fmt, tf, (unsigned long)arg);
	else
		pf_print_hex(fmt, tf, (unsigned int)arg);
}
