/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:12:08 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 16:12:32 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_subprint_decimal(char **fmt, t_format *tf, char **k, char **p)
{
	ft_strdel(k);
	ft_strdel(p);
	if (tf->flags->add_space_if_no_sign && !(tf->flags->show_sign) &&
			(int)ft_strlen(*fmt) == tf->min_width && tf->precision_value == -1)
	{
		*p = ft_strsub(*fmt, 1, ft_strlen(*fmt) - 1);
		ft_strdel(fmt);
		*fmt = ft_strjoin(" ", *p);
		ft_strdel(p);
	}
}

static void	pf_print_decimal(char **fmt, t_format *tf, long arg)
{
	int		i;
	char	*t;
	char	*p;
	char	*k;

	*fmt = pf_ltoa(arg);
	pf_handle_precision_1(fmt, tf, arg, &k);
	pf_handle_precision_2(*fmt, tf, &k, &p);
	pf_handle_width(*fmt, tf, &k, &p);
	t = (ft_strlen(p)) ? ft_strjoin(p, *fmt) : ft_strjoin(*fmt, p);
	i = (k[0] == '0') ? 0 : 1;
	(i == 1) ? pf_handle_sign(&t, tf, arg) : 0;
	pf_handle_space(&t, tf, k);
	ft_strdel(&p);
	ft_strdel(fmt);
	if ((tf->flags->show_sign || arg < 0) && ft_strlen(k) > 0)
	{
		p = ft_strsub(k, 1, ft_strlen(k) - 1);
		ft_strdel(&k);
		k = ft_strdup(p);
	}
	*fmt = (tf->flags->justify_left) ? ft_strjoin(t, k) : ft_strjoin(k, t);
	(i == 0) ? pf_handle_sign(fmt, tf, arg) : 0;
	ft_strdel(&t);
	pf_subprint_decimal(fmt, tf, &k, &p);
}

void		pf_handle_decimal(char **fmt, t_format *tf, void *arg)
{
	if (tf->length == 1 && tf->type != 6)
		pf_print_decimal(fmt, tf, (char)arg);
	else if (tf->length == 2 && tf->type != 6)
		pf_print_decimal(fmt, tf, (short)arg);
	else if (tf->length == 3 || tf->length == 4 || tf->type == 6)
		pf_print_decimal(fmt, tf, (long)arg);
	else if (tf->length == 5)
		pf_print_decimal(fmt, tf, (long)arg);
	else if (tf->length == 6)
		pf_print_decimal(fmt, tf, (long)arg);
	else
		pf_print_decimal(fmt, tf, (int)arg);
}
