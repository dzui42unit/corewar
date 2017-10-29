/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:31:38 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/16 15:33:23 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	*pf_create_str(char *fmt)
{
	t_string	*new_str;

	new_str = (t_string*)malloc(sizeof(t_string));
	new_str->str = fmt;
	new_str->len = 0;
	new_str->next = NULL;
	return (new_str);
}

void		pf_fill_string(t_format *tf, char **fmt, void *arg)
{
	tf->type == 1 ? pf_handle_ptr(fmt, tf, arg) : 0;
	tf->type == 2 ? pf_handle_ptr(fmt, tf, arg) : 0;
	tf->type == 3 ? pf_handle_string(fmt, tf, arg) : 0;
	tf->type == 4 ? pf_handle_string(fmt, tf, arg) : 0;
	tf->type == 5 ? pf_handle_decimal(fmt, tf, arg) : 0;
	tf->type == 6 ? pf_handle_decimal(fmt, tf, arg) : 0;
	tf->type == 7 ? pf_handle_octal(fmt, tf, arg) : 0;
	tf->type == 8 ? pf_handle_octal(fmt, tf, arg) : 0;
	tf->type == 9 ? pf_handle_unsigned(fmt, tf, arg) : 0;
	tf->type == 10 ? pf_handle_unsigned(fmt, tf, arg) : 0;
	tf->type == 11 ? pf_handle_hex(fmt, tf, arg) : 0;
	tf->type == 12 ? pf_handle_hex(fmt, tf, arg) : 0;
	tf->type == 13 ? pf_handle_char(fmt, tf, arg) : 0;
	tf->type == 14 ? pf_handle_char(fmt, tf, arg) : 0;
	tf->type == 15 ? pf_handle_binary(fmt, tf, arg) : 0;
	tf->type == 16 ? pf_handle_binary(fmt, tf, arg) : 0;
	tf->type == 17 ? pf_handle_decimal(fmt, tf, arg) : 0;
}

static void	pf_create_format_struct(t_format **tf)
{
	*tf = (t_format*)malloc(sizeof(t_format));
	(*tf)->flags = (t_flags*)malloc(sizeof(t_flags));
	(*tf)->flags->justify_left = 0;
	(*tf)->flags->show_sign = 0;
	(*tf)->flags->add_space_if_no_sign = 0;
	(*tf)->flags->alter_form = 0;
	(*tf)->flags->add_zeros = 0;
	(*tf)->min_width = 0;
	(*tf)->precision_flag = 0;
	(*tf)->precision_value = -1;
	(*tf)->length = 0;
	(*tf)->type = 0;
}

int			pf_parse_format(char *fmt, int *chars_p, t_format **tf)
{
	int		i;
	int		f;
	int		p;
	int		l;

	i = 0;
	f = 1;
	p = 1;
	l = 1;
	pf_create_format_struct(tf);
	while (f || p || l)
	{
		f = pf_get_flags_and_width(fmt, *tf, &i);
		p = pf_get_precision(fmt, *tf, &i);
		l = pf_get_length(fmt, *tf, &i);
	}
	pf_get_type(fmt, *tf, &i);
	if ((*tf)->type != 18)
		*chars_p = 1;
	return (i);
}
