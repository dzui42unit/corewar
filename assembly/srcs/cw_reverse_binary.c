/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_reverse_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:18:54 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:18:56 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	cw_reverse_save_instructions(size_t size, unsigned char buff[size],
											unsigned int memory[MEMORY_SIZE])
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && buff[i] == 0)
		i++;
	while (i < size)
		memory[j++] = buff[i++];
}

static int	cw_reverse_file_open(char *file_name)
{
	int		fd;

	fd = 0;
	if (open(file_name, O_RDONLY) > 0)
	{
		ft_putendl("Input can't be a directory");
		exit(-1);
	}
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		ft_printf("Can't read source file %s\n", file_name);
		exit(-1);
	}
	return (fd);
}

void		cw_reverse_binary(int argc, char **argv)
{
	int				fd;
	size_t			size;
	unsigned char	buff[PROG_NAME_LENGTH + COMMENT_LENGTH + 16];
	unsigned int	memory[MEMORY_SIZE];
	unsigned int	program_size;

	size = PROG_NAME_LENGTH + COMMENT_LENGTH;
	fd = cw_reverse_file_open(argv[FILE]);
	read(fd, buff, size);
	program_size = cw_reverse_header(size, buff);
	size = program_size + 16;
	size = read(fd, buff, size);
	cw_reverse_save_instructions(size, buff, memory);
	cw_reverse_instructions(memory, program_size);
	close(fd);
}
