/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_open_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:31:29 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:32:23 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_open_in: Check the input file, it's format and option parameter,
** if the file is good (not too long, not a directory, .s) and can be opened,
** save file name and input's fd in t_in.
*/

static int	cw_open_error(char *file_name, int *fd)
{
	char	*file_type;

	if (open(file_name, O_DIRECTORY) > 0)
	{
		ft_putendl("Input can't be a directory");
		return (-1);
	}
	if ((*fd = open(file_name, O_RDONLY)) < 0)
	{
		ft_putendl("Can't read source file");
		return (-1);
	}
	if (ft_strlen(file_name) > 128)
	{
		ft_putendl("File name is too long (> 128 char)");
		return (-1);
	}
	if ((file_type = ft_strstr(file_name, ".s")) == NULL ||
			ft_strlen(file_type) > 2)
	{
		ft_putendl("Wrong file type - [.s] is needed");
		return (-1);
	}
	return (0);
}

int			cw_open_in(int argc, char **argv, t_in *data_in)
{
	data_in->fd = 0;
	ft_bzero(data_in->file_name, 129);
	if (cw_open_error(argv[FILE], &data_in->fd) == -1)
		return (-1);
	ft_strcat(data_in->file_name, argv[FILE]);
	return (0);
}
