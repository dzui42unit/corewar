/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_assembly_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:20:38 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:20:40 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		cw_assembly_data(t_data *data)
{
	if (cw_create_param_byte(&data->parse.instr_list) == -1)
		return (-1);
	if (cw_get_program_data(&data->parse.instr_list, &data->header) == -1)
		return (-1);
	if (cw_set_tag_value(&data->parse.instr_list) == -1)
		return (-1);
	return (0);
}
