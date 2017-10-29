/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_save_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:13:04 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:13:05 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_parse_save_code : Parse each line_code to check the validity of the code
** and save the code in t_instr.
*/

static int	cw_iscode_undefined(t_instr *current, char **code_name)
{
	if (current->code == -10)
	{
		if (*code_name != NULL && *code_name[0] != '\0')
			ft_printf("Unknown instruction : '%s' - Line %d\n", *code_name,
							current->line_nbr);
		else
			ft_printf("Undefined instruction syntax - Line %d\n",
							current->line_nbr);
		ft_strdel(&(*code_name));
		return (-1);
	}
	return (0);
}

int			cw_parse_save_code(t_instr **instr_list)
{
	t_instr	*current;
	char	*code_name;

	current = *instr_list;
	code_name = NULL;
	while (current != NULL)
	{
		if (current->line_code != NULL)
		{
			if ((current->code = cw_parse_get_code(current->line_code,
													&code_name)) == -1)
			{
				ft_strdel(&code_name);
				return (-1);
			}
			if (cw_iscode_undefined(current, &code_name) == -1)
				return (-1);
			if (!(current->args_line = ft_strtrim(current->line_code +
													ft_strlen(code_name))))
				return (-1);
			ft_strdel(&code_name);
		}
		current = current->next;
	}
	return (0);
}
