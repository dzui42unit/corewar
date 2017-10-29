/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_display_details.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:22:30 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 14:10:30 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			cw_display_arg_value(int type, int value, int i)
{
	if (type == REG_CODE)
		cw_display_hex(value, REG_OCTET);
	else if (type == DIR_CODE && i == 1)
		cw_display_hex(value, DIR_OCTET_INDEX);
	else if (type == DIR_CODE)
		cw_display_hex(value, DIR_OCTET);
	else if (type == IND_CODE)
		cw_display_hex(value, IND_OCTET);
}

static const char	*cw_get_type(int type)
{
	if (type == REG_CODE)
		return ("Register");
	else if (type == DIR_CODE)
		return ("Direct");
	else if (type == IND_CODE)
		return ("Indirect");
	return ("");
}

static void			cw_check_each(t_instr *instr_list)
{
	t_args	*current;

	current = instr_list->args_list;
	ft_printf("%s%-5s%s ⇨  [%#.2x] ", GOLD, g_op_tab[instr_list->code].name,
										DEFAULT, instr_list->code);
	if (g_op_tab[instr_list->code].param_byte == 1)
		ft_printf("0b%.8b - %#2x", instr_list->param_byte,
									instr_list->param_byte);
	else
		ft_printf("%10s ", " ");
	while (current != NULL)
	{
		ft_printf("\n%32s %s ➜ %s  %s%-8s%s → [%-8s - ", " ",
					B_GREEN, DEFAULT, B_RED, current->content, DEFAULT,
					cw_get_type(current->type));
		cw_display_arg_value(current->type, current->value1,
					g_op_tab[instr_list->code].has_index);
		ft_putchar(']');
		current = current->next;
	}
	ft_putchar('\n');
}

void				cw_display_details(t_instr *instr_list, t_header header)
{
	t_instr	*current;

	current = instr_list;
	ft_printf("Details of binary compilation\n");
	ft_printf("Program size : %d bytes - %#x\n", header.prog_size,
													header.prog_size);
	ft_printf("Champion's comment : \"%s\"\n", header.comment);
	ft_printf("Champion's name : \"%s\"\n", header.prog_name);
	ft_printf("Magic number : %#x\n\n", COREWAR_EXEC_MAGIC);
	while (current != NULL)
	{
		if (current->tag_name != NULL)
			ft_printf(":%s\n", current->tag_name);
		if (current->code > 0)
			cw_check_each(current);
		current = current->next;
	}
}
