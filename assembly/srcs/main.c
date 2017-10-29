/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:26:28 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 13:05:05 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define SUCCESS 0
#define FAIL -1

static void	cw_print_use(int argc, char **argv)
{
	if (argc <= 1 || ft_strcmp(argv[FILE], "-d") == 0 ||
					ft_strcmp(argv[FILE], "-details") == 0 ||
					ft_strcmp(argv[FILE], "-r") == 0 ||
					ft_strcmp(argv[FILE], "-rev") == 0)
	{
		ft_putendl("Usage: ./asm [-details/-d | -rev/-r] <sourcefile.s>");
		ft_putendl("       -details : Instead of creating a .cor file,");
		ft_putendl("                  outputs a separated and annotated");
		ft_putendl("                  version of the code to the standard");
		ft_putendl("                  output.");
		ft_putendl("       -rev     : Disassemble a .cor file by writing on");
		ft_putendl("                  the standard output pseudo-asm code");
		ft_putendl("                  of this .cor file.");
		exit(-1);
	}
}

int			main(int argc, char **argv)
{
	t_data	data;

	cw_print_use(argc, argv);
	if (ft_strcmp(argv[OPTION], "-r") == 0 ||
			ft_strcmp(argv[OPTION], "-rev") == 0)
		cw_reverse_binary(argc, argv);
	else
	{
		if (cw_open_in(argc, argv, &data.in) == -1)
			return (cw_free_and_exit(&data.parse.instr_list, FAIL, &data));
		if (cw_parse_in(&data) == -1)
			return (cw_free_and_exit(&data.parse.instr_list, FAIL, &data));
		if (cw_assembly_data(&data) == -1)
			return (cw_free_and_exit(&data.parse.instr_list, FAIL, &data));
		if (ft_strcmp(argv[OPTION], "-d") == 0 ||
				ft_strcmp(argv[OPTION], "-details") == 0)
			cw_display_details(data.parse.instr_list, data.header);
		else
		{
			if (cw_make_binary(&data) == -1)
				return (cw_free_and_exit(&data.parse.instr_list, FAIL, &data));
		}
		cw_free_and_exit(&data.parse.instr_list, SUCCESS, &data);
	}
	return (0);
}
