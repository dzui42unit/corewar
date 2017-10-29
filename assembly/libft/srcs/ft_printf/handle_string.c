/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:23:48 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/16 14:29:13 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_subprint_string_2(char **fmt, t_format *tf, void *arg, int *len)
{
	char	*str;

	if (arg)
		str = pf_gen_wstr((wchar_t*)arg, len);
	else
		str = ft_strdup("(null)");
	if (tf->precision_flag && tf->precision_value < 0)
		tf->precision_value = 0;
	if (tf->precision_value > -1 && tf->precision_value < (int)ft_strlen(str))
		*fmt = pf_gen_nwstr((wchar_t*)arg, tf->precision_value);
	else
		*fmt = ft_strdup(str);
	ft_strdel(&str);
}

static void	pf_print_string_2(char **fmt, t_format *tf, void *arg)
{
	int		len;
	char	*t;
	char	*p;
	char	*k;

	pf_subprint_string_2(fmt, tf, arg, &len);
	pf_handle_precision_2(*fmt, tf, &k, &p);
	pf_handle_width(*fmt, tf, &k, &p);
	len = (ft_strlen(k)) ? ft_strlen(p) : 0;
	ft_strdel(&p);
	p = ft_strnew(len);
	k = (tf->flags->add_zeros) ? ft_memset(k, '0', ft_strlen(k)) : k;
	p = ft_memset(p, ' ', len);
	t = ft_strjoin(p, *fmt);
	ft_strdel(fmt);
	ft_strdel(&p);
	*fmt = (tf->flags->justify_left) ? ft_strjoin(t, k) : ft_strjoin(k, t);
	ft_strdel(&t);
	ft_strdel(&k);
}

static void	pf_subprint_string_1(char **fmt, t_format *tf, char **t, char **k)
{
	char	*p;

	ft_strdel(fmt);
	*fmt = (tf->flags->justify_left) ? ft_strjoin(*t, *k) : ft_strjoin(*k, *t);
	ft_strdel(k);
	ft_strdel(t);
	if ((int)ft_strlen(*fmt) < tf->min_width)
	{
		*t = ft_strdup(*fmt);
		p = ft_strnew(tf->min_width - ft_strlen(*fmt));
		p = ft_memset(p, ' ', tf->min_width - ft_strlen(*fmt));
		ft_strdel(fmt);
		*fmt = tf->flags->justify_left ? ft_strjoin(*t, p) :
											ft_strjoin(p, *t);
		ft_strdel(t);
		ft_strdel(&p);
	}
}

static void	pf_print_string_1(char **fmt, t_format *tf, void *arg)
{
	char	*t;
	char	*p;
	char	*k;
	char	*str;
	int		len;

	str = (arg) ? ft_strdup((char*)arg) : ft_strdup("(null)");
	if (tf->precision_flag && tf->precision_value < 0)
		tf->precision_value = 0;
	if (tf->precision_value > -1 && tf->precision_value < (int)ft_strlen(str))
		*fmt = ft_strsub(str, 0, tf->precision_value);
	else
		*fmt = ft_strdup(str);
	ft_strdel(&str);
	pf_handle_precision_2(*fmt, tf, &k, &p);
	pf_handle_width(*fmt, tf, &k, &p);
	len = (ft_strlen(k)) ? ft_strlen(p) : 0;
	ft_strdel(&p);
	p = ft_strnew(len);
	p = ft_memset(p, ' ', len);
	k = (tf->flags->add_zeros && !(tf->flags->justify_left)) ?
		ft_memset(k, '0', ft_strlen(k)) : k;
	t = ft_strjoin(p, *fmt);
	ft_strdel(&p);
	pf_subprint_string_1(fmt, tf, &t, &k);
}

void		pf_handle_string(char **fmt, t_format *tf, void *arg)
{
	if (tf->length == 3 || tf->length == 4 || tf->type == 4)
		pf_print_string_2(fmt, tf, arg);
	else
		pf_print_string_1(fmt, tf, arg);
}
