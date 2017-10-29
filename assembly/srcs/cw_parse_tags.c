/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_tags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:16:22 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:16:23 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define LINE parse->free_line

/*
** cw_parse_tags : Check the validity (exist?) of a tag (argument in t_args)
** and set the tag_name, tag_line in parsing structure.
*/

static int		is_tag(t_parse *parse, char *content)
{
	char	*free;

	free = NULL;
	if (!(parse->tag_name = ft_strdup(content)))
	{
		ft_strdel(&content);
		return (-1);
	}
	if (ft_strchr(LINE, LABEL_CHAR) != NULL)
		free = ft_strchr(LINE, LABEL_CHAR) + 1;
	if (!(parse->tag_line = ft_strdup(LINE)))
		return (-1);
	ft_strdel(&LINE);
	if (!(LINE = ft_strtrim(free)))
		return (-1);
	return (1);
}

static int		is_tag_chars(int c)
{
	if (ft_strchr(LABEL_CHARS, (char)c) != NULL)
		return (0);
	else
		return (1);
}

static int		is_separator_tag(int c)
{
	if (c == DIRECT_CHAR || c == '-')
		return (1);
	if (ft_isspace(c))
		return (1);
	return (0);
}

static int		cw_check_tag_line(t_parse *parse, char *content)
{
	if (content != NULL)
	{
		if (!(ft_str_condition_fulfilling(content, is_separator_tag)))
		{
			if (ft_str_condition_fulfilling(content, is_tag_chars) != 1)
				return (is_tag(parse, content));
			else if (ft_str_condition_fulfilling(content, is_tag_chars) == 1)
			{
				ft_putendl("Unauthorised character(s) in label :");
				ft_printf("'%s' - Line %d\n", content, parse->line_nbr);
				return (-1);
			}
		}
	}
	return (0);
}

int				cw_parse_tags(t_parse *parse)
{
	int		i;
	int		out;
	char	*content;

	i = 0;
	content = NULL;
	while (LINE[i] != '\0')
	{
		if (LINE[i] == LABEL_CHAR)
		{
			if (!(content = ft_strndup(LINE, ft_charindex(LINE, LABEL_CHAR))))
				return (-1);
			break ;
		}
		i++;
	}
	out = cw_check_tag_line(parse, content);
	ft_strdel(&content);
	return (out);
}
