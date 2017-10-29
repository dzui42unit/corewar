/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:12:37 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 19:12:41 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

void		ft_go_through_proc(t_vm *vm, t_process *pr, int i)
{
	t_process	*start;

	attron(COLOR_PAIR(vm->color_map[i]));
	ft_print_pc(vm, pr, i);
	start = pr;
	if (vm->iter[i] > 0)
		attron(A_BOLD);
	attron(COLOR_PAIR(vm->color_map[i]));
	ft_print_pc(vm, start, i);
	while (pr)
	{
		if (vm->iter[i] > 100)
		{
			attron(COLOR_PAIR((vm->iter[i] / 100 + 30)));
			attron(A_BOLD);
			if (vm->iter[i] % 100 == 50)
				vm->iter[i] = 0;
		}
		pr = pr->next;
	}
	if (vm->iter[i] != 0 && vm->iter[i] < 50)
		attron(A_BOLD);
}

void		draw_memmory(t_vm *vm, t_process *proc)
{
	int i;
	int	x;
	int	y;

	i = 0;
	y = 2;
	x = 3;
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	while (i < MEM_SIZE)
	{
		ft_go_through_proc(vm, proc, i);
		mvwprintw(stdscr, y, x, "%.2x", vm->memory[i]);
		attroff(A_BOLD);
		if (vm->iter[i] > 0 && vm->play)
			vm->iter[i]--;
		i++;
		x += 3;
		if ((i % 64) == 0)
		{
			x = 3;
			y++;
		}
		attron(COLOR_PAIR(6));
	}
}

void		draw_players(t_player *head)
{
	t_player	*start;
	int			i;

	i = 1;
	start = head;
	while (start)
	{
		draw_player_info(start, i);
		i++;
		start = start->next;
	}
}

void		ft_count_percentage_2(t_vm *vm, t_player *pl)
{
	t_player	*head;
	int			i;

	i = 0;
	head = pl;
	while (head)
	{
		vm->br_down_color[i] = (50 * vm->br_down_color[i]) / 100;
		if (((vm->cycles + 1) % vm->cycle_to_die == 0) && vm->cycles != 0)
			vm->prev_br_down_color[i] = vm->br_down_color[i];
		i++;
		head = head->next;
	}
}

void		ft_count_percentage(t_vm *vm, t_player *pl)
{
	t_player	*head;
	int			i;
	float		total;

	i = 0;
	total = 0;
	head = pl;
	while (head)
	{
		total += head->live_in_curr_period;
		head = head->next;
	}
	head = pl;
	while (head)
	{
		vm->br_down_color[i] = ((head->live_in_curr_period) * 100) / total;
		head = head->next;
		i++;
	}
	ft_count_percentage_2(vm, pl);
}
