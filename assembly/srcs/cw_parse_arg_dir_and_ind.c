/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_arg_dir_and_ind.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:43:51 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:49:31 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_parse_arg_dir_and_ind : Check if arguments Direct and Indirect
** are correct.
*/

static int		cw_isstr_expression_char(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '+' && str[i] != '-'
				&& str[i] != '*' && str[i] != '/' && str[i] != '%'
				&& !ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (1);
}

static int		cw_isarg_empty(char *content, int args_nbr, int line_nbr)
{
	if (*content == '\0')
	{
		ft_printf("Syntax error - argument %d (null) - Line %d\n",
							args_nbr, line_nbr);
		return (-1);
	}
	return (0);
}

static int		cw_exist_tag(t_instr *instr_list, char *tag_to_check)
{
	t_instr	*temp_instr;

	temp_instr = instr_list;
	while (temp_instr != NULL)
	{
		if (temp_instr->tag_name != NULL)
		{
			if (ft_strcmp(temp_instr->tag_name, tag_to_check) == 0)
				return (1);
		}
		temp_instr = temp_instr->next;
	}
	return (0);
}

static int		cw_arg_with_tag(t_args *current, char args_nbr, int line_nbr,
								t_instr *check_tag)
{
	char	*content;

	content = (current->type < 3) ? current->content + 1 : current->content;
	if (ft_charindex(content, ' ') != -1)
	{
		if (cw_parse_eval_expr_tag(current, args_nbr, line_nbr, check_tag))
			return (-1);
	}
	else
	{
		if (cw_exist_tag(check_tag, content + 1) == 0)
		{
			ft_printf("Undefined label [arg %d] - Line %d\n",
					args_nbr, line_nbr);
			return (-1);
		}
		current->tag = content + 1;
	}
	return (0);
}

int				cw_parse_arg_dir_and_ind(t_args *current, char args_nbr,
											int line_nbr, t_instr *check_tag)
{
	char	*content;

	content = (current->type < 3) ? current->content + 1 : current->content;
	if (current->type == DIR_CODE || current->type == IND_CODE)
	{
		if (cw_isarg_empty(content, args_nbr, line_nbr) == -1)
			return (-1);
		if (*content == LABEL_CHAR)
		{
			if (cw_arg_with_tag(current, args_nbr, line_nbr, check_tag) == -1)
				return (-1);
		}
		else if (cw_isnumber_syntax(content, 1) == 1)
			current->value1 = cw_lltoi(content);
		else if (cw_isstr_expression_char(content) == 1)
			return (cw_parse_eval_expr(current, args_nbr, line_nbr));
		else
		{
			ft_printf("Undefined syntax [arg %d] - Line %d\n",
												args_nbr, line_nbr);
			return (-1);
		}
	}
	return (0);
}
