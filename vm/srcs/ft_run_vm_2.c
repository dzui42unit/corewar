/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_vm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:18:31 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 19:18:32 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

void	ft_reset_live_in_period(t_player *pl)
{
	t_player *head;

	head = pl;
	while (head)
	{
		head->live_in_curr_period = 0;
		head = head->next;
	}
}

void	ft_total_lives(t_vm *vm, t_player *pl)
{
	t_player *head;

	head = pl;
	vm->total_lives = 0;
	while (head)
	{
		vm->total_lives += head->live_in_curr_period;
		head = head->next;
	}
}

void	ft_clear_args(t_process *pr)
{
	int i;

	i = 0;
	while (i < 3)
	{
		pr->args[i] = 0;
		i++;
	}
	pr->arg_1 = 0;
	pr->arg_2 = 0;
	pr->arg_3 = 0;
	pr->correct_args = 1;
}

void	ft_copy_value(t_vm *vm, t_process *pr, short start, unsigned int value)
{
	int pl_nb;

	start == MEM_SIZE ? start = 0 : 0;
	pl_nb = ft_get_number_of_pl(vm->head_pl, pr->pl_belongs) + 1;
	vm->color_map[start] = pl_nb;
	vm->iter[start] = 50;
	vm->memory[start] = (unsigned char)((value >> 24) & 0xFF);
	start++;
	start == MEM_SIZE ? start = 0 : 0;
	vm->color_map[start] = pl_nb;
	vm->iter[start] = 50;
	vm->memory[start] = (unsigned char)((value >> 16) & 0xFF);
	start++;
	start == MEM_SIZE ? start = 0 : 0;
	vm->color_map[start] = pl_nb;
	vm->iter[start] = 50;
	vm->memory[start] = (unsigned char)((value >> 8) & 0xFF);
	start++;
	start == MEM_SIZE ? start = 0 : 0;
	vm->color_map[start] = pl_nb;
	vm->iter[start] = 50;
	vm->memory[start] = (unsigned char)((value) & 0xFF);
}

void	ft_draw_init(t_vm *vm, t_process *proc)
{
	ft_init_color_map(vm, proc);
	initscr();
	raw();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	curs_set(0);
	start_color();
	draw_frame();
	vm->ct = 0;
}
