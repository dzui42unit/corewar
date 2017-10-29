/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:51:29 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 15:56:24 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_append_filler(char *fmt, t_string **str, int i, int chars_p)
{
	t_string	*tmp;

	tmp = *str;
	if (*str)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = pf_create_str(ft_strsub(fmt, i - chars_p, chars_p));
	}
	else
		*str = pf_create_str(ft_strsub(fmt, i - chars_p, chars_p));
	return (0);
}

static void	pf_append_assist(char *fmt, t_string **tmp, t_format *tf)
{
	while ((*tmp)->next)
		*tmp = (*tmp)->next;
	(*tmp)->next = pf_create_str(ft_strdup(fmt));
	if (tf->type == 13 && tf->length < 3)
		(*tmp)->next->len = tf->min_width ? tf->min_width : 1;
	else if (tf->type == 14)
	{
		if (tf->min_width)
			(*tmp)->next->len = tf->min_width + ft_strlen(fmt) - 1;
		else
		{
			if (ft_strlen(fmt) == 0)
				(*tmp)->next->len = 1;
			else
				(*tmp)->next->len = ft_strlen(fmt);
		}
	}
}

void		pf_append_str(char *fmt, t_string **str, t_format *tf)
{
	t_string	*tmp;

	tmp = *str;
	if (*str)
		pf_append_assist(fmt, &tmp, tf);
	else
	{
		*str = pf_create_str(ft_strdup(fmt));
		if (tf->type == 13 && tf->length < 3)
			tmp->len = tf->min_width ? tf->min_width : 1;
		else if (tf->type == 14)
		{
			if (tf->min_width)
				tmp->len = tf->min_width + ft_strlen(fmt) - 1;
			else
			{
				if (ft_strlen(fmt) == 0)
					tmp->len = 1;
				else
					tmp->len = ft_strlen(fmt);
			}
		}
	}
}

int			pf_append_result(char *fmt, va_list *args, t_string **str,
								t_format **tf)
{
	char	*tmp;

	if ((*tf)->type > 0)
		pf_fill_string(*tf, &tmp, va_arg(*args, void*));
	else
	{
		pf_handle_err(fmt, str, tf);
		return (1);
	}
	pf_append_str(tmp, str, *tf);
	free((*tf)->flags);
	free(*tf);
	free(tmp);
	return (0);
}
