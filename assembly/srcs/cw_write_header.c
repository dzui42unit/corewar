/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_write_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:25:46 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:25:48 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_write_header : Write the header (Magic number, name, program size,
** comment) in a file descriptor.
*/

static void	cw_write_str(int fd, char *str, int length)
{
	int		i;
	int		word_length;
	char	zero;

	i = 0;
	word_length = ft_strlen(str);
	zero = 0;
	while (i < length)
	{
		if (i < word_length)
			write(fd, &(str[i]), 1);
		else
			write(fd, &zero, 1);
		i++;
	}
}

void		cw_write_header(int fd, t_header header)
{
	cw_write_byte(fd, COREWAR_EXEC_MAGIC, 4);
	cw_write_str(fd, header.prog_name, PROG_NAME_LENGTH + 4);
	cw_write_byte(fd, header.prog_size, 4);
	cw_write_str(fd, header.comment, COMMENT_LENGTH + 4);
}
