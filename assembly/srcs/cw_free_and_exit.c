/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_free_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:26:52 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:26:55 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	cw_del_args_list(t_args **args_list)
{
	t_args	*temp_args;

	temp_args = *args_list;
	while (temp_args != NULL)
	{
		ft_strdel(&temp_args->content);
		temp_args = temp_args->next;
	}
}

int			cw_free_and_exit(t_instr **instr_list, int type, t_data *data)
{
	t_instr		*temp_instr;

	temp_instr = *instr_list;
	while (temp_instr != NULL)
	{
		temp_instr->line_nbr = 0;
		temp_instr->is_tag = 0;
		ft_strdel(&temp_instr->tag_line);
		ft_strdel(&temp_instr->tag_name);
		ft_strdel(&temp_instr->line_code);
		ft_strdel(&temp_instr->args_line);
		cw_del_args_list(&temp_instr->args_list);
		temp_instr = temp_instr->next;
	}
	close(data->in.fd);
	close(data->out.fd);
	return (type);
}
