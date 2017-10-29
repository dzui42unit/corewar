/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_validate_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:18:03 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:18:05 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_parse_validate_args : Check if the arguments for a code used are allowed.
** Example :
** code = g_op_tab[code].arg_types[args_nbr] & current->t_arg
** ---> code = (T_REG | T_DIR) & T_IND;
** If the result is NULL the argument used is unauthorised
** else it is authorised.
*/

static int	cw_arg_error(t_args *current, int code, int line_nbr, int args_nbr)
{
	if (current->type == REG_CODE)
		ft_printf("Invalid parameter %d type %s for instruction '%s' - Line %d"
				"\n", args_nbr + 1, "register", g_op_tab[code].name, line_nbr);
	else if (current->type == IND_CODE)
		ft_printf("Invalid parameter %d type %s for instruction '%s' - Line %d"
				"\n", args_nbr + 1, "indirect", g_op_tab[code].name, line_nbr);
	else if (current->type == DIR_CODE)
		ft_printf("Invalid parameter %d type %s for instruction '%s' - Line %d"
				"\n", args_nbr + 1, "direct", g_op_tab[code].name, line_nbr);
	return (-1);
}

static int	cw_check_arguments(t_instr *instr_list, int op_code, int line_nbr)
{
	t_args	*current;
	int		args_nbr;
	int		code;

	args_nbr = 0;
	current = instr_list->args_list;
	while (current != NULL)
	{
		if ((code = (g_op_tab[op_code].arg_types[args_nbr] &
				current->t_arg)) == 0)
			return (cw_arg_error(current, code, line_nbr, args_nbr));
		current = current->next;
		args_nbr++;
	}
	return (0);
}

int			cw_parse_validate_args(t_instr **instr_list)
{
	t_instr	*current;

	current = *instr_list;
	while (current != NULL)
	{
		if (current->args_line)
		{
			if (cw_check_arguments(current, current->code,
									current->line_nbr) == -1)
				return (-1);
		}
		current = current->next;
	}
	return (0);
}
