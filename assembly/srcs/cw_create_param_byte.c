/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_create_param_byte.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:21:35 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:21:38 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_create_param_byte : Build and put in the elements param_byte of the
** linked list t_instr the binary value created with the type of each argument.
** Example :
** 		>> r2  --> 0b01 |
**		>> 23  --> 0b11 |--> Binary value --> 0b01111000 --> 0x78
**		>> %34 --> 0b10 |
*/

static void	cw_check_each(t_instr *instr_lst)
{
	t_args	*current;
	int		byte_offset;

	current = instr_lst->args_list;
	byte_offset = 6;
	while (current != NULL)
	{
		instr_lst->param_byte = (current->type << byte_offset) |
				instr_lst->param_byte;
		current = current->next;
		byte_offset -= 2;
	}
}

int			cw_create_param_byte(t_instr **instr_list)
{
	t_instr	*current;

	current = *instr_list;
	while (current != NULL)
	{
		if (g_op_tab[current->code].param_byte == 1)
			cw_check_each(current);
		current = current->next;
	}
	return (0);
}
