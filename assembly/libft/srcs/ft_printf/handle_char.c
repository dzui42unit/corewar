/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:09:50 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 16:45:13 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_print_char_1(char **fmt, t_format *tf, void *arg)
{
	int		i;

	*fmt = ft_strnew(1);
	*fmt[0] = (char)arg;
	if (tf->min_width > 0)
	{
		ft_strdel(fmt);
		*fmt = ft_strnew(tf->min_width);
		i = -1;
		if (!(tf->flags->justify_left))
		{
			while (++i < tf->min_width - 1)
				(*fmt)[i] = (tf->flags->add_zeros) ? '0' : ' ';
			(*fmt)[i] = (char)arg;
		}
		else
		{
			(*fmt)[++i] = (char)arg;
			while (++i < tf->min_width)
				(*fmt)[i] = (tf->flags->add_zeros) ? '0' : ' ';
		}
	}
}

static void	pf_subprint_char_2(char **fmt, void *arg, int *d)
{
	if ((int)arg < 256)
	{
		*fmt = ft_strnew(1);
		(*fmt)[0] = (int)arg - 256;
	}
	else
		*fmt = pf_wchar_to_char((wchar_t)arg);
	*d = ft_strlen(*fmt);
}

static void	pf_print_char_2(char **fmt, t_format *tf, void *arg)
{
	int		i;
	int		d;
	int		h;
	char	*t;

	pf_subprint_char_2(fmt, arg, &d);
	if ((h = -1) && tf->min_width > 0)
	{
		ft_strdel(fmt);
		t = pf_wchar_to_char((wchar_t)arg);
		*fmt = ft_strnew(tf->min_width + d - 1);
		if ((i = -1) && !(tf->flags->justify_left))
		{
			while (++i < tf->min_width - 1)
				(*fmt)[i] = (tf->flags->add_zeros) ? '0' : ' ';
			while (++h < d)
				(*fmt)[i + h] = t[h];
		}
		else
		{
			(*fmt)[++i] = (char)arg;
			while (++i < tf->min_width)
				(*fmt)[i] = (tf->flags->add_zeros) ? '0' : ' ';
		}
	}
}

void		pf_handle_char(char **fmt, t_format *tf, void *arg)
{
	if (tf->length == 3 || tf->length == 4 || tf->type == 14)
		pf_print_char_2(fmt, tf, arg);
	else
		pf_print_char_1(fmt, tf, arg);
}
