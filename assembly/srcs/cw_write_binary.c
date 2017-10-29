/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_write_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:24:04 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:24:06 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_write_binary : Run linked list with the input data in order to write this
** data in the memory output file .cor.
*/

static void	cw_check_each(t_instr **instr_list, int fd)
{
	t_args	*current;

	current = (*instr_list)->args_list;
	cw_write_byte(fd, (*instr_list)->code, 1);
	if (g_op_tab[(*instr_list)->code].param_byte == 1)
		cw_write_byte(fd, (*instr_list)->param_byte, 1);
	while (current != NULL)
	{
		if (current->type == REG_CODE)
			cw_write_byte(fd, current->value1, REG_OCTET);
		else if (current->type == DIR_CODE &&
				(g_op_tab[(*instr_list)->code].has_index == 1))
			cw_write_byte(fd, current->value1, DIR_OCTET_INDEX);
		else if (current->type == DIR_CODE)
			cw_write_byte(fd, current->value1, DIR_OCTET);
		else if (current->type == IND_CODE)
			cw_write_byte(fd, current->value1, IND_OCTET);
		current = current->next;
	}
}

int			cw_write_binary(t_instr **instr_list, t_out *out_file)
{
	t_instr	*current;

	current = *instr_list;
	while (current != NULL)
	{
		if (current->code > 0)
			cw_check_each(&current, out_file->fd);
		current = current->next;
	}
	return (0);
}
