/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:15:27 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/16 17:00:26 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_subprint_1_octal(char **fmt, char **t, char **p,
								unsigned long arg)
{
	char	*k;

	k = (arg) ? ft_strjoin("0", *t) : ft_strdup(*t);
	ft_strdel(t);
	*t = ft_strjoin(k, *fmt);
	ft_strdel(fmt);
	ft_strdel(&k);
	*fmt = ft_strjoin(*p, *t);
}

static int	pf_subprint_2_octal(char **fmt, t_format *tf, char **p,
								unsigned long arg)
{
	char	*k;

	if ((size_t)tf->precision_value < (ft_strlen(*p) + ft_strlen(*fmt) + 1) &&
			arg > 0)
	{
		if (ft_strlen(*p) == 0)
			k = ft_strsub(*p, 0, ft_strlen(*p));
		else
			k = ft_strsub(*p, 0, ft_strlen(*p) - 1);
		ft_strdel(p);
		*p = ft_strdup(k);
		ft_strdel(&k);
	}
	if (arg > 0 || tf->precision_flag)
		k = ft_strjoin("0", *p);
	else
		k = ft_strdup(*p);
	ft_strdel(p);
	*p = ft_strjoin(k, *fmt);
	ft_strdel(fmt);
	ft_strdel(&k);
	return (1);
}

static void	pf_subprint_3_octal(char **fmt, t_format *tf, char **k, char **p)
{
	char	*t;

	t = (ft_strlen(*p)) ? ft_strjoin(*p, *fmt) : ft_strjoin(*fmt, *p);
	ft_strdel(fmt);
	*fmt = (tf->flags->justify_left) ? ft_strjoin(t, *k) : ft_strjoin(*k, t);
	ft_strdel(k);
	ft_strdel(&t);
}

static void	pf_print_octal(char **fmt, t_format *tf, unsigned long arg)
{
	char	*t;
	char	*p;
	char	*k;

	*fmt = pf_ltoa_base(arg, 8, "01234567");
	pf_handle_precision_1(fmt, tf, arg, &k);
	pf_handle_precision_2(*fmt, tf, &k, &p);
	pf_handle_width(*fmt, tf, &k, &p);
	if (tf->flags->alter_form)
	{
		t = (ft_strlen(k) > 0) ? ft_strsub(k, 1, ft_strlen(k) - 1) :
				ft_strdup("");
		ft_strdel(&k);
		if (tf->flags->add_zeros && !(tf->flags->justify_left) &&
				tf->precision_value == -1)
			pf_subprint_1_octal(fmt, &t, &p, arg);
		else if (pf_subprint_2_octal(fmt, tf, &p, arg))
			*fmt = (tf->flags->justify_left) ? ft_strjoin(p, t) :
												ft_strjoin(t, p);
		ft_strdel(&t);
	}
	else
		pf_subprint_3_octal(fmt, tf, &k, &p);
	ft_strdel(&p);
}

void		pf_handle_octal(char **fmt, t_format *tf, void *arg)
{
	if (tf->length == 1 && tf->type != 8)
		pf_print_octal(fmt, tf, (unsigned char)arg);
	else if (tf->length == 2 && tf->type != 8)
		pf_print_octal(fmt, tf, (unsigned short)arg);
	else if (tf->length == 3 || tf->length == 4 || tf->type == 8)
		pf_print_octal(fmt, tf, (unsigned long)arg);
	else if (tf->length == 5)
		pf_print_octal(fmt, tf, (unsigned long)arg);
	else if (tf->length == 6)
		pf_print_octal(fmt, tf, (unsigned long)arg);
	else
		pf_print_octal(fmt, tf, (unsigned int)arg);
}
