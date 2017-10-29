/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_save_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:11:34 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:11:35 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_parse_save_args : Check the validity of each argument of t_args and set
** the argument type (0b01 - 0b10 - 0b11) for each instruction of t_instr.
*/

static int	cw_isindirect(int c)
{
	return ((c >= '0' && c <= '9') || c == '-' || c == LABEL_CHAR);
}

static int	cw_arg_register_type(t_args *current, char args_nbr, int line_nbr)
{
	char	*content;

	content = (current->type < 3) ? current->content + 1 : current->content;
	if (current->type == REG_CODE)
	{
		if (cw_isnumber_syntax(content, 0) == -1 || *content == '\0')
		{
			ft_printf("Invalid number for register type [arg %d]  - Line %d\n",
						args_nbr, line_nbr);
			return (-1);
		}
		current->value1 = cw_lltoi(content);
		if (current->value1 > REG_NUMBER ||
			ft_strlen(content) > cw_intlen(REG_NUMBER))
		{
			ft_printf("Only %d register(s) available [arg %d] - Line %d\n",
						REG_NUMBER, args_nbr, line_nbr);
			return (-1);
		}
	}
	return (0);
}

static int	cw_arg_type(t_args *current, char args_nbr, int line_nbr)
{
	if (*current->content == 'r')
	{
		current->type = REG_CODE;
		current->t_arg = T_REG;
	}
	else if (*current->content == DIRECT_CHAR)
	{
		current->type = DIR_CODE;
		current->t_arg = T_DIR;
	}
	else if (cw_isindirect(*current->content) == 1)
	{
		current->type = IND_CODE;
		current->t_arg = T_IND;
	}
	else
	{
		ft_printf("Invalid syntax [arg %d] - Line %d\n", args_nbr, line_nbr);
		return (-1);
	}
	return (0);
}

static int	cw_check_arguments(t_instr *instr_list, t_instr *check_tag)
{
	t_args	*current;
	char	args_nbr;
	char	*temp_content;

	current = instr_list->args_list;
	args_nbr = 0;
	while (current != NULL)
	{
		args_nbr++;
		temp_content = current->content;
		ft_strdel(&current->content);
		if (!(current->content = ft_strtrim(temp_content)))
			return (-1);
		if (cw_arg_type(current, args_nbr, instr_list->line_nbr) == -1)
			return (-1);
		if (cw_arg_register_type(current, args_nbr, instr_list->line_nbr) == -1)
			return (-1);
		if (cw_parse_arg_dir_and_ind(current, args_nbr, instr_list->line_nbr,
										check_tag) == -1)
			return (-1);
		current = current->next;
	}
	return (0);
}

int			cw_parse_save_args(t_instr **instr_list)
{
	t_instr	*current;
	t_instr	*check_tag;

	current = *instr_list;
	check_tag = *instr_list;
	while (current != NULL)
	{
		if (current->args_line)
		{
			if (cw_check_arguments(current, check_tag) == -1)
				return (-1);
		}
		current = current->next;
	}
	return (0);
}
