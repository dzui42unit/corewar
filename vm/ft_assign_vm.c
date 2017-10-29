/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:11:36 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:11:37 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_set_vm_default_parameters(t_vm *vm)
{
	int i;

	i = 0;
	vm->check = 0;
	vm->cycles = 0;
	vm->processes = 0;
	vm->nbr_cycles = -1;
	vm->nbr_live = 0;
	vm->pl_index = 0;
	vm->avail_nb = 1;
	vm->play = 0;
	vm->total_lives = 0;
	vm->visual = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->speed = 2;
	while (i < MAX_PLAYERS)
	{
		vm->name_files[i] = NULL;
		vm->number[i] = 0;
		i++;
	}
}

void		ft_clear_memory(t_vm *vm)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm->memory[i] = 0;
		vm->iter[i] = 0;
		i++;
	}
}

void		ft_assign_memory(t_vm *vm, t_player *head_pl, t_process **head_proc)
{
	t_player	*start;
	int			i;
	int			j;
	int			limit;

	j = 0;
	start = head_pl;
	limit = (MEM_SIZE) / vm->pl_index;
	ft_clear_memory(vm);
	while (start)
	{
		i = 0;
		if (*head_proc == NULL)
			*head_proc = ft_create_process(*head_proc, start, j);
		else
			ft_add_process(head_proc, start, j);
		while (i < CHAMP_MAX_SIZE)
		{
			vm->memory[j] = start->inctructions[i];
			i++;
			j++;
		}
		j += (limit - CHAMP_MAX_SIZE);
		start = start->next;
	}
}

void		ft_print_vm_data(t_vm *vm)
{
	int i;

	i = 0;
	ft_printf("check: %d\n", vm->check);
	ft_printf("cycles: %d\n", vm->cycles);
	ft_printf("processes: %d\n", vm->processes);
	ft_printf("nbr_cycles: %d\n", vm->nbr_cycles);
	ft_printf("nbr_live = %d\n", vm->nbr_live);
	ft_printf("cycle_to_die = %d\n", vm->cycle_to_die);
	ft_printf("pl_index = %d\n", vm->pl_index);
	while (i < MAX_PLAYERS)
	{
		ft_printf("File name: %s. Number = %ld\n",
				vm->name_files[i], vm->number[i]);
		i++;
	}
}
