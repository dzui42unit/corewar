/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_reverse_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:20:46 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:20:48 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	cw_reverse_byte_value(unsigned int memory[MEMORY_SIZE],
									char octet_nbr, size_t *i)
{
	int		byte_offset;
	int		out;

	out = 0;
	byte_offset = 8 * (octet_nbr - 1);
	while (byte_offset >= 0)
	{
		out = (memory[*i] << byte_offset) | out;
		byte_offset -= 8;
		(*i)++;
	}
	return (out);
}

static int	cw_reverse_get_arg_type(unsigned int value, char byte[3])
{
	int		byte_offset;
	int		i;

	byte_offset = 6;
	i = 0;
	while (byte_offset >= 2)
	{
		byte[i] = (value >> byte_offset) & 3;
		byte_offset -= 2;
		i++;
	}
	return (i);
}

static void	cw_reverse_multiple_args(unsigned int memory[MEMORY_SIZE],
										size_t *i, short code)
{
	int		j;
	char	byte[3];

	cw_reverse_get_arg_type(memory[*i], byte);
	(*i)++;
	j = 0;
	while (j < g_op_tab[code].nb_args)
	{
		if (byte[j] == REG_CODE)
			ft_printf("r%d", cw_reverse_byte_value(memory, REG_OCTET, &(*i)));
		else if (byte[j] == IND_CODE)
			ft_printf("%d", cw_reverse_byte_value(memory, IND_OCTET, &(*i)));
		else if (byte[j] == DIR_CODE)
		{
			if (g_op_tab[code].has_index == 0)
				ft_printf("%%%d", cw_reverse_byte_value(memory, DIR_OCTET,
														&(*i)));
			else
				ft_printf("%%%d", cw_reverse_byte_value(memory, DIR_OCTET_INDEX,
														&(*i)));
		}
		j == (g_op_tab[code].nb_args - 1) ? ft_putchar('\n') : ft_putchar(',');
		j++;
	}
}

void		cw_reverse_instructions(unsigned int memory[MEMORY_SIZE],
									size_t program_size)
{
	size_t	i;
	short	code;

	i = 0;
	while (i < program_size)
	{
		if (i >= MEMORY_SIZE)
			ft_printf("%s\n", "Not a valid file");
		code = memory[i++];
		if (code > 16)
			code = 0;
		if (g_op_tab[code].name)
			ft_printf("\t%s ", g_op_tab[code].name);
		if (g_op_tab[code].param_byte == 1)
			cw_reverse_multiple_args(memory, &i, code);
		else
		{
			if (g_op_tab[code].has_index == 0)
				ft_printf("%%%d\n", cw_reverse_byte_value(memory, DIR_OCTET,
														&i));
			else
				ft_printf("%%%d\n", cw_reverse_byte_value(memory,
														DIR_OCTET_INDEX, &i));
		}
	}
}
