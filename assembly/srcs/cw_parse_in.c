/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:02:00 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 13:37:54 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define CONTINUE 5

static int	cw_parse_content(t_parse *parse)
{
	int	out;

	if (parse->saved_name == 1 && parse->saved_comment == 1)
	{
		out = cw_parse_tags(parse);
		if (out == -1)
			return (-1);
		if (out == 1)
		{
			if (!(parse->line_code = ft_strdup(parse->free_line)))
				return (-1);
			return (0);
		}
		ft_strdel(&(parse->tag_line));
		if (!(parse->line_code = ft_strdup(parse->free_line)))
			return (-1);
	}
	return (0);
}

static int	cw_analyze_line(t_parse *parse, t_header *header, char **line)
{
	if (!(parse->free_line = cw_strcomment_trim(*line, COMMENT_CHAR)))
		return (-1);
	if (*parse->free_line == '\0')
	{
		ft_strdel(&parse->free_line);
		ft_strdel(&(*line));
		return (CONTINUE);
	}
	if (cw_parse_content(parse) == -1)
		return (-1);
	cw_parse_name_and_comment(parse, header);
	if (cw_parse_add_instruction(&parse->instr_list, parse) == -1)
		return (-1);
	cw_parse_struct_clean(parse);
	return (0);
}

static int	cw_analyze_instruction(t_parse *parse)
{
	if (cw_parse_save_code(&parse->instr_list) == -1)
		return (-1);
	if (cw_parse_get_args(&parse->instr_list) == -1)
		return (-1);
	if (cw_parse_save_args(&parse->instr_list) == -1)
		return (-1);
	if (cw_parse_validate_args(&parse->instr_list) == -1)
		return (-1);
	cw_parse_struct_clean(parse);
	return (0);
}

int			cw_parse_in(t_data *data)
{
	char	*line;
	int		out;

	line = NULL;
	cw_parse_struct_init(&data->parse);
	while (get_next_line(data->in.fd, &line) > 0)
	{
		data->parse.line_nbr++;
		if ((out = cw_analyze_line(&data->parse, &data->header, &line)) == -1)
		{
			cw_parse_struct_clean(&data->parse);
			ft_strdel(&line);
			return (-1);
		}
		if (out == CONTINUE)
			continue ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (cw_analyze_instruction(&data->parse) == -1)
		return (-1);
	return (0);
}
