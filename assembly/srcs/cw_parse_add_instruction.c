/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_add_instruction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:32:57 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:32:59 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_parse_add_instruction : Add at the end of the linked list t_instr
** an instruction (line) with the line, the line label, the label and
** the line_code content.
*/

static void		cw_initialize_element(t_instr **instr)
{
	(*instr)->line_nbr = 0;
	(*instr)->is_tag = 0;
	(*instr)->tag_line = NULL;
	(*instr)->tag_name = NULL;
	(*instr)->line_code = NULL;
	(*instr)->code = -1;
	(*instr)->args_list = NULL;
	(*instr)->args_line = NULL;
	(*instr)->param_byte = 0;
	(*instr)->octet_index = 0;
}

static t_instr	*cw_add_element(t_parse *content)
{
	t_instr	*new_instr;

	if (!(new_instr = (t_instr*)malloc(sizeof(t_instr))))
		return (NULL);
	cw_initialize_element(&new_instr);
	new_instr->line_nbr = content->line_nbr;
	if (content->tag_line != NULL)
	{
		if (!(new_instr->tag_line = ft_strdup(content->tag_line)))
			return (NULL);
		new_instr->is_tag = 1;
		if (!(new_instr->tag_name = ft_strdup(content->tag_name)))
			return (NULL);
	}
	if (content->line_code != NULL && *content->line_code != '\0')
		if (!(new_instr->line_code = ft_strdup(content->line_code)))
			return (NULL);
	return (new_instr);
}

int				cw_parse_add_instruction(t_instr **list_head, t_parse *content)
{
	t_instr		*new_element;

	new_element = *list_head;
	if (*list_head == NULL)
	{
		if (!(*list_head = cw_add_element(content)))
			return (-1);
		(*list_head)->next = NULL;
	}
	else
	{
		while (new_element->next != NULL)
			new_element = new_element->next;
		if (!(new_element->next = cw_add_element(content)))
			return (-1);
		new_element->next->next = NULL;
	}
	return (1);
}
