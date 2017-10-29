/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_set_tag_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:23:05 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:23:07 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_set_tag_value : Set the value of each argument using label (result
** between current index octet and label's index octet) and the
** result of the calculation.
*/

static int	cw_evaluate_expression(t_args *arg)
{
	int	out;

	out = 0;
	if (arg->code == '+')
		out = arg->value1 + arg->value2;
	else if (arg->code == '-')
		out = arg->value1 - arg->value2;
	else if (arg->code == '*')
		out = arg->value1 * arg->value2;
	else if (arg->code == '/')
	{
		if (arg->value2 == 0)
			return (0);
		out = arg->value1 / arg->value2;
	}
	else if (arg->code == '%')
	{
		if (arg->value2 == 0)
			return (0);
		out = arg->value1 % arg->value2;
	}
	return (out);
}

static int	cw_get_tag_octet_index(t_instr *instr_list, char *current_tag)
{
	t_instr	*current;

	current = instr_list;
	while (current != NULL)
	{
		if (current->tag_name != NULL)
		{
			if (ft_strcmp(current->tag_name, current_tag) == 0)
				return (current->octet_index);
		}
		current = current->next;
	}
	return (0);
}

static void	cw_check_each(t_instr **instr_list, t_instr *instr_list_start)
{
	t_args	*current;

	current = (*instr_list)->args_list;
	while (current != NULL)
	{
		if (current->tag != NULL)
		{
			current->value1 = cw_get_tag_octet_index(instr_list_start,
				current->tag) - (*instr_list)->octet_index;
		}
		if (current->code != 0)
			current->value1 = cw_evaluate_expression(current);
		current = current->next;
	}
}

int			cw_set_tag_value(t_instr **instr_list)
{
	t_instr	*current;

	current = *instr_list;
	while (current != NULL)
	{
		if (current->code > 0)
			cw_check_each(&current, *instr_list);
		current = current->next;
	}
	return (0);
}
