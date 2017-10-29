/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:57:24 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/16 13:40:50 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_print_str(char *fmt, t_string *str, int *chars_p, int i)
{
	t_string	*tmp;

	*chars_p = pf_append_filler(fmt, &str, i, *chars_p);
	while (str)
	{
		if (str->len > 0)
		{
			i = -1;
			while (++i < str->len)
				ft_putchar((str->str)[i]);
			*chars_p += str->len;
		}
		else if (str->str)
		{
			ft_putstr(str->str);
			*chars_p += ft_strlen(str->str);
		}
		tmp = str;
		str = str->next;
		ft_strdel(&(tmp->str));
		free(tmp);
	}
	ft_strdel(&fmt);
	return (*chars_p);
}

static int	pf_subprintf(const char *format, va_list *args)
{
	char		*fmt;
	int			chars_p;
	int			i;
	t_string	*str;
	t_format	*tf;

	i = 0;
	str = 0;
	chars_p = 0;
	fmt = ft_strdup(format);
	while (fmt[i] != '\0' && i <= (int)ft_strlen(fmt))
	{
		if (fmt[i] == '%')
		{
			chars_p = pf_append_filler(fmt, &str, i, chars_p);
			i += pf_parse_format(fmt + i + 1, &chars_p, &tf);
			(chars_p) ? i += pf_append_result(fmt + i + 1, args, &str, &tf) :
							pf_handle_pct(&str, &tf);
			chars_p = 0;
		}
		else
			chars_p++;
		i++;
	}
	return (pf_print_str(fmt, str, &chars_p, i));
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			chars_p;

	va_start(args, format);
	chars_p = pf_subprintf(format, &args);
	va_end(args);
	return (chars_p);
}
