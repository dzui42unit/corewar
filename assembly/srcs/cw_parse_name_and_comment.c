/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_name_and_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:09:11 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:09:12 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_parse_name_and_comment : Check if the header is well formatted and put
** the name and comment in the header structure.
** .name "my_name"
** .comment "my_comment"
*/

static void	cw_parse_undefinded(t_parse *parse)
{
	if (parse->saved_name == 0 && parse->saved_comment == 0)
	{
		ft_putendl("Name and Comment undefined");
		exit(-1);
	}
	else if (parse->saved_name == 0)
	{
		ft_putendl("Champion name undefined");
		exit(-1);
	}
	else if (parse->saved_comment == 0)
	{
		ft_putendl("Champion comment undefined");
		exit(-1);
	}
}

static void	cw_check_ifsaved(t_parse *parse, char flag)
{
	if (ft_strncmp(parse->free_line, NAME_CMD_STRING,
					ft_strlen(NAME_CMD_STRING)) == 0 && flag == 1)
	{
		if (parse->saved_name == 0)
			parse->saved_name = 1;
		else
		{
			ft_printf("Champion name already defined - Line %d\n",
							parse->line_nbr);
			exit(-1);
		}
	}
	else if (ft_strncmp(parse->free_line, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) == 0 && flag == 0)
	{
		if (parse->saved_comment == 0)
			parse->saved_comment = 1;
		else
		{
			ft_printf("Champion comment already defined - Line %d\n",
						parse->line_nbr);
			exit(-1);
		}
	}
}

int			cw_parse_name_and_comment(t_parse *parse, t_header *header)
{
	cw_parse_check_header(NAME_CMD_STRING, PROG_NAME_LENGTH, parse, header);
	cw_check_ifsaved(parse, 1);
	cw_parse_check_header(COMMENT_CMD_STRING, COMMENT_LENGTH, parse, header);
	cw_check_ifsaved(parse, 0);
	if (ft_strncmp(parse->free_line,
				NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) != 0 &&
			ft_strncmp(parse->free_line,
				COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) != 0)
		cw_parse_undefinded(parse);
	return (0);
}
