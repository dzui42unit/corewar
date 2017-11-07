/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:26:03 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:26:04 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

int		ft_check_dump_flag(t_vm *vm)
{
	(vm->argv)++;
	if (!(*(vm->argv)))
		ft_error("Error: Invalid dump value");
	if (ft_is_numberic_string(*(vm->argv)))
	{
		vm->nbr_cycles = ft_atoi_dec(*(vm->argv));
		(vm->argv)++;
		return (1);
	}
	else
		ft_error("Error: Invalid dump value");
	return (0);
}

int		ft_check_pl_number(t_vm *vm)
{
	(vm->argv)++;
	if (!(*(vm->argv)))
		ft_error("Error: Invalid champion number");
	if (ft_is_numberic_string(*(vm->argv)))
	{
		vm->number[vm->pl_index] = ft_atoi_dec(*(vm->argv));
		(vm->argv)++;
		if (!(*(vm->argv)))
			ft_error("Error: Invalid champion number");
		if (ft_strequ(*(vm->argv), "-dump")
			|| ft_strequ(*(vm->argv), "-v") || ft_strequ(*(vm->argv), "-n"))
			ft_error("Error: Invalid champion number");
		vm->name_files[vm->pl_index] = ft_strdup(*(vm->argv));
		vm->pl_index++;
		(vm->argv)++;
		return (1);
	}
	else
		ft_error("Error: Invalid champion number");
	return (0);
}

void	ft_process_args(t_vm *vm)
{
	(vm->argv)++;
	while (*(vm->argv))
	{
		if (ft_strequ(*(vm->argv), "-v"))
		{
			vm->visual = 1;
			(vm->argv)++;
			continue ;
		}
		if (ft_strequ(*(vm->argv), "-dump"))
			if (ft_check_dump_flag(vm))
				continue ;
		if (ft_strequ(*(vm->argv), "-n"))
			if (ft_check_pl_number(vm))
				continue ;
		if (vm->pl_index == (MAX_PLAYERS))
			ft_error("Too many champions");
		vm->name_files[vm->pl_index] = ft_strdup(*(vm->argv));
		vm->number[vm->pl_index] = vm->avail_nb;
		vm->pl_index++;
		vm->avail_nb++;
		(vm->argv)++;
	}
}

int		ft_check_file_name(char *name)
{
	char	**split;
	int		i;

	i = 0;
	if (ft_strlen(name) <= 4)
		ft_error("Ivalid file name.");
	split = ft_strsplit(name, '.');
	while (split[i + 1])
		i++;
	if (!ft_strequ(split[i], "cor"))
		return (0);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (1);
}
