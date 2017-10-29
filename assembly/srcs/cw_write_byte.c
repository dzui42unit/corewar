/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_write_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:24:50 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:24:52 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_write_byte : Write an unsigned int in a file descriptor on n octet(s).
*/

void	cw_write_byte(int fd, unsigned int value, char octet_nbr)
{
	int		byte_offset;
	char	octet;

	byte_offset = 8 * (octet_nbr - 1);
	while (byte_offset >= 0)
	{
		octet = (value >> byte_offset) & 0xFF;
		write(fd, &octet, 1);
		byte_offset -= 8;
	}
}
