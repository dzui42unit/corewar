/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:29:14 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/16 16:37:09 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_get_flags_and_width(char *fmt, t_format *tf, int *i)
{
	long	width;

	if (fmt[*i] != '-' && fmt[*i] != '+' &&
			fmt[*i] != ' ' && fmt[*i] != '#' &&
			(fmt[*i] < '0' || fmt[*i] > '9'))
		return (0);
	if (fmt[*i] == '-' && ++(*i))
		tf->flags->justify_left = 1;
	else if (fmt[*i] == '+' && ++(*i))
		tf->flags->show_sign = 1;
	else if (fmt[*i] == ' ' && ++(*i))
		tf->flags->add_space_if_no_sign = 1;
	else if (fmt[*i] == '#' && ++(*i))
		tf->flags->alter_form = 1;
	else if (fmt[*i] == '0' && ++(*i))
		tf->flags->add_zeros = 1;
	else if (fmt[*i] >= '0' && fmt[*i] <= '9')
	{
		width = 0;
		while (fmt[*i] >= '0' && fmt[*i] <= '9')
			width = width * 10 + fmt[(*i)++] - '0';
		tf->min_width = width;
	}
	return (1);
}

int			pf_get_precision(char *fmt, t_format *tf, int *i)
{
	long	precision;

	if (fmt[*i] == '.' && ++(*i))
	{
		tf->precision_flag = 1;
		if (fmt[*i] >= '0' && fmt[*i] <= '9')
		{
			precision = 0;
			while (fmt[*i] >= '0' && fmt[*i] <= '9')
				precision = precision * 10 + fmt[(*i)++] - '0';
			tf->precision_value = precision;
		}
		else
			tf->precision_value = 0;
		return (1);
	}
	return (0);
}

int			pf_get_length(char *fmt, t_format *tf, int *i)
{
	if (fmt[*i] != 'h' && fmt[*i] != 'l' && fmt[*i] != 'j' && fmt[*i] != 'z')
		return (0);
	else if (fmt[*i] == 'h' && fmt[*i + 1] == 'h' && tf->length < 1
			&& ((*i) += 2))
		tf->length = 1;
	else if (fmt[*i] == 'h' && tf->length < 2 && ++(*i))
		tf->length = 2;
	else if (fmt[*i] == 'l' && fmt[*i + 1] == 'l' && tf->length < 3
			&& ((*i) += 2))
		tf->length = 3;
	else if (fmt[*i] == 'l' && tf->length < 4 && ++(*i))
		tf->length = 4;
	else if (fmt[*i] == 'j' && tf->length < 5 && ++(*i))
		tf->length = 5;
	else if (fmt[*i] == 'z' && tf->length < 6 && ++(*i))
		tf->length = 6;
	else
		++(*i);
	return (1);
}

static void	pf_get_type_more(char *fmt, t_format *tf, int *i)
{
	if (fmt[*i] == 'x' && ++(*i))
		tf->type = 11;
	else if (fmt[*i] == 'X' && ++(*i))
		tf->type = 12;
	else if (fmt[*i] == 'c' && ++(*i))
		tf->type = 13;
	else if (fmt[*i] == 'C' && ++(*i))
		tf->type = 14;
	else if (fmt[*i] == 'b' && ++(*i))
		tf->type = 15;
	else if (fmt[*i] == 'B' && ++(*i))
		tf->type = 16;
	else if (fmt[*i] == 'i' && ++(*i))
		tf->type = 17;
	else if (fmt[*i] == '%' && ++(*i))
		tf->type = 18;
}

void		pf_get_type(char *fmt, t_format *tf, int *i)
{
	if (fmt[*i] == 'p' && ++(*i))
		tf->type = 1;
	else if (fmt[*i] == 'P' && ++(*i))
		tf->type = 2;
	else if (fmt[*i] == 's' && ++(*i))
		tf->type = 3;
	else if (fmt[*i] == 'S' && ++(*i))
		tf->type = 4;
	else if (fmt[*i] == 'd' && ++(*i))
		tf->type = 5;
	else if (fmt[*i] == 'D' && ++(*i))
		tf->type = 6;
	else if (fmt[*i] == 'o' && ++(*i))
		tf->type = 7;
	else if (fmt[*i] == 'O' && ++(*i))
		tf->type = 8;
	else if (fmt[*i] == 'u' && ++(*i))
		tf->type = 9;
	else if (fmt[*i] == 'U' && ++(*i))
		tf->type = 10;
	else
		pf_get_type_more(fmt, tf, i);
}
