/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:15:53 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:15:55 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	cw_parse_struct_init(t_parse *parse)
{
	parse->line_nbr = 0;
	parse->tag_name = NULL;
	parse->tag_line = NULL;
	parse->line_code = NULL;
	parse->args_line = NULL;
	parse->free_line = NULL;
	parse->instr_list = NULL;
	parse->saved_name = 0;
	parse->saved_comment = 0;
	parse->saved_comment_name = 0;
}

void	cw_parse_struct_clean(t_parse *parse)
{
	ft_strdel(&parse->tag_name);
	ft_strdel(&parse->tag_line);
	ft_strdel(&parse->line_code);
	ft_strdel(&parse->args_line);
	ft_strdel(&parse->free_line);
}
