/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_reverse_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:19:53 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:19:54 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static unsigned int	cw_reverse_bytes_to_uint(unsigned char *ptr, size_t nbr)
{
	unsigned int	out;

	out = 0;
	if (nbr > 4)
		ft_printf("Error: trying to store %lu bytes in an int\n", nbr);
	while (nbr > 0)
	{
		out = (out << 8) | (unsigned int)(*ptr);
		ptr++;
		nbr--;
	}
	return (out);
}

static void			cw_reverse_check_magic(unsigned char *buff)
{
	unsigned int	nbr;

	nbr = cw_reverse_bytes_to_uint(buff, 4);
	if (nbr != COREWAR_EXEC_MAGIC)
	{
		ft_putendl("Error: Not a valid file");
		exit(-1);
	}
}

unsigned int		cw_reverse_header(size_t size, unsigned char buff[size])
{
	unsigned int	program_size;
	size_t			i;

	i = 0;
	cw_reverse_check_magic(buff);
	i += 4;
	ft_printf("%s \"", NAME_CMD_STRING);
	while (i < size && buff[i])
		ft_putchar(buff[i++]);
	while (i < PROG_NAME_LENGTH)
		i++;
	ft_printf("\"\n%s \"", COMMENT_CMD_STRING);
	program_size = cw_reverse_bytes_to_uint(&buff[i + 8], 4);
	i += 12;
	while (i < size && buff[i])
		ft_putchar(buff[i++]);
	ft_putstr("\"\n\n");
	return (program_size);
}
