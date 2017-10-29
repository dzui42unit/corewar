/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_make_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:29:23 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:30:52 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	cw_generate_binary(t_data *data)
{
	cw_write_header(data->out.fd, data->header);
	if (cw_write_binary(&data->parse.instr_list, &data->out) == -1)
		return (-1);
	return (0);
}

static int	cw_create_binary(t_in in)
{
	char	*file_name;
	int		file_fd;

	if (!(file_name = ft_strndup(in.file_name, cw_strindex(in.file_name,
															".s"))))
		return (-1);
	if (!(file_name = cw_strjoin_and_free(file_name, ".cor")))
	{
		ft_strdel(&file_name);
		return (-1);
	}
	file_fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |
			S_IRGRP | S_IROTH, 0777);
	if (file_fd == -1)
	{
		ft_strdel(&file_name);
		return (-1);
	}
	ft_printf("Writing output program to %s\n", file_name);
	ft_strdel(&file_name);
	return (file_fd);
}

int			cw_make_binary(t_data *data)
{
	if (data->header.prog_size == 0)
	{
		ft_putendl("No enough data to generate a binary file player - Program"
											" size : 0 bytes");
		return (-1);
	}
	else
	{
		if ((data->out.fd = cw_create_binary(data->in)) == -1)
			return (-1);
		if (cw_generate_binary(data) == -1)
			return (-1);
	}
	return (0);
}
