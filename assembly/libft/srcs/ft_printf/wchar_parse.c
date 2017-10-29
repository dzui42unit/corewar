/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:33:06 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/13 16:33:48 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_wchar_to_char(wchar_t const n)
{
	char *c;

	c = ft_strnew(4);
	if (n <= 0x7F)
		c[0] = n;
	else if (n <= 0x7FF)
	{
		c[0] = (n >> 6) + 0xC0;
		c[1] = (n & 0x3F) + 0x80;
	}
	else if (n <= 0xFFFF)
	{
		c[0] = (n >> 12) + 0xE0;
		c[1] = ((n >> 6) & 0x3F) + 0x80;
		c[2] = (n & 0x3F) + 0x80;
	}
	else if (n <= 0x10FFFF)
	{
		c[0] = (n >> 18) + 0xF0;
		c[1] = ((n >> 12) & 0x3F) + 0x80;
		c[2] = ((n >> 6) & 0x3F) + 0x80;
		c[3] = (n & 0x3F) + 0x80;
	}
	return (c);
}

char		*pf_gen_wstr(wchar_t *n, int *len)
{
	char	*str;
	char	*tmp;
	char	*next;

	*len = 0;
	str = 0;
	if (n == NULL)
		return (ft_strdup("(null)"));
	while (*n && ++(*len))
	{
		next = pf_wchar_to_char(*n);
		if (str)
		{
			tmp = ft_strdup(str);
			ft_strdel(&str);
			str = ft_strjoin(tmp, next);
			ft_strdel(&tmp);
		}
		else
			str = ft_strdup(next);
		ft_strdel(&next);
		n++;
	}
	(!str) ? str = ft_strdup("") : 0;
	return (str);
}

static void	pf_subgen_nwstr(wchar_t **n, char **next, char **tmp, char **str)
{
	*next = pf_wchar_to_char(**n);
	if (*str)
	{
		*tmp = ft_strdup(*str);
		ft_strdel(str);
		*str = ft_strjoin(*tmp, *next);
		ft_strdel(tmp);
	}
	else
		*str = ft_strdup(*next);
	ft_strdel(next);
}

char		*pf_gen_nwstr(wchar_t *n, int d)
{
	char	*str;
	char	*tmp;
	char	*next;
	char	*fmt;

	fmt = 0;
	str = 0;
	if (n == NULL)
		return (ft_strdup("(null)"));
	while (*n)
	{
		pf_subgen_nwstr(&n, &next, &tmp, &str);
		if ((int)ft_strlen(str) > d)
		{
			ft_strdel(&str);
			return (fmt = (fmt) ? fmt : ft_strdup(""));
		}
		(fmt) ? ft_strdel(&fmt) : 0;
		fmt = ft_strdup(str);
		n++;
	}
	if (!str)
		str = ft_strdup("");
	return (str);
}
