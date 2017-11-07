/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:22:11 by dzui              #+#    #+#             */
/*   Updated: 2017/10/31 16:48:08 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

void	ft_run_visual_mode(t_vm *vm, t_process **process, t_player *players)
{
	t_process *proc_head;

	ft_draw_init(vm, *process);
	while (vm->cycle_to_die > 0 && (*process != NULL))
	{
		ft_visual(vm, players, *process);
		if (vm->play)
		{
			ft_total_lives(vm, players);
			if (vm->cycles != 0 && vm->ct == vm->cycle_to_die)
				ft_delete_process(players, process, vm);
			ft_count_cycles_state(vm);
			proc_head = *process;
			while (proc_head)
			{
				ft_process_instruction(proc_head, vm, process);
				proc_head = proc_head->next;
			}
			vm->cycles++;
			vm->ct++;
			refresh();
		}
	}
	while (1)
		ft_visual(vm, players, *process);
}

void	ft_del_element(t_process **head, t_process *del)
{
	t_process *start;
	t_process *temp_n;

	if (*head == NULL)
		return ;
	if (*head == del)
	{
		temp_n = (*head)->next;
		free(*head);
		*head = temp_n;
		return ;
	}
	start = *head;
	while (start && start->next != del)
		start = start->next;
	if (start != NULL)
	{
		temp_n = start->next->next;
		free(start->next);
		start->next = temp_n;
	}
}

void	ft_delete_process(t_player *players, t_process **pr, t_vm *vm)
{
	t_process	*start;
	t_player	*pl;

	pl = players;
	start = *pr;
	while (start)
	{
		if (start->live == 0)
		{
			ft_del_element(pr, start);
			vm->processes--;
		}
		start = start->next;
	}
	start = *pr;
	while (start)
	{
		start->live = 0;
		start = start->next;
	}
	ft_reset_live_in_period(players);
}

void	ft_count_cycles_state(t_vm *vm)
{
	if (vm->cycles == vm->nbr_cycles && !vm->visual)
	{
		ft_print_memory(vm);
		exit(0);
	}
	if ((vm->ct == vm->cycle_to_die)
		&& (vm->total_lives >= NBR_LIVE))
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->check = 0;
		vm->ct = 0;
	}
	if ((vm->ct == vm->cycle_to_die)
		&& (vm->total_lives < NBR_LIVE))
	{
		vm->check++;
		if (vm->check == 10)
		{
			vm->cycle_to_die -= CYCLE_DELTA;
			vm->check = 0;
		}
		vm->ct = 0;
	}
}

void	ft_run_normal_mode(t_vm *vm, t_process **process, t_player *players)
{
	t_process *proc_head;

	vm->ct = 0;
	while (vm->cycle_to_die > 0 && (*process != NULL))
	{
		ft_total_lives(vm, players);
		if (vm->ct == vm->cycle_to_die)
			ft_delete_process(players, process, vm);
		ft_count_cycles_state(vm);
		proc_head = *process;
		while (proc_head)
		{
			ft_process_instruction(proc_head, vm, process);
			proc_head = proc_head->next;
		}
		vm->cycles++;
		vm->ct++;
	}
	ft_print_champ(vm, players);
}
