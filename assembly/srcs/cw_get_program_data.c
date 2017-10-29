/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_program_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:27:26 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:45:19 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_get_program_data : Set the value of octet_index of each element of
** t_instr, get the program size. The octet_index is determined by incrementing
** prog_size (t_header).
*/

static void	cw_check_each(t_instr **instr_list, t_header *header)
{
	t_args	*current;

	current = (*instr_list)->args_list;
	header->prog_size += 1;
	if (g_op_tab[(*instr_list)->code].param_byte == 1)
		header->prog_size += 1;
	while (current != NULL)
	{
		if (current->type == REG_CODE)
			header->prog_size += REG_OCTET;
		else if (current->type == DIR_CODE &&
				(g_op_tab[(*instr_list)->code].has_index == 1))
			header->prog_size += DIR_OCTET_INDEX;
		else if (current->type == DIR_CODE)
			header->prog_size += DIR_OCTET;
		else if (current->type == IND_CODE)
			header->prog_size += IND_OCTET;
		current = current->next;
	}
}

int			cw_get_program_data(t_instr **instr_list, t_header *header)
{
	t_instr			*current;

	current = *instr_list;
	header->prog_size = 0;
	while (current != NULL)
	{
		current->octet_index = header->prog_size;
		if (current->code > 0)
			cw_check_each(&current, header);
		current = current->next;
	}
	return (0);
}
