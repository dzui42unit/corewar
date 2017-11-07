/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:13:27 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 19:13:28 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_print_pc(t_vm *vm, t_process *proc, int i)
{
	t_process *start;

	start = proc;
	while (start)
	{
		if (start->pc == i)
		{
			if (vm->color_map[i] != 0)
				attron(COLOR_PAIR(20 + vm->color_map[i]));
			else
				attron(COLOR_PAIR(66));
			return ;
		}
		start = start->next;
	}
}

int			ft_empty_br_line(t_vm *vm)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (vm->prev_br_down_color[i] != 0.0)
			return (0);
		i++;
	}
	return (1);
}

void		ft_draw_data_2(t_vm *vm, t_player *pl, int move_output)
{
	if (vm->total_lives == 0)
		mvwprintw(stdscr, move_output + 8, 200,
				"[--------------------------------------------------]");
	else
	{
		mvwprintw(stdscr, move_output + 8, 200, "[");
		ft_count_percentage(vm, pl);
		ft_print_live_break_down(vm, move_output + 8, 201);
	}
	mvwprintw(stdscr, move_output + 10, 202,
			"Live breakdown for last period :");
	if (vm->cycles < CYCLE_TO_DIE || ft_empty_br_line(vm))
		mvwprintw(stdscr, move_output + 11, 200,
				"[--------------------------------------------------]");
	else
	{
		mvwprintw(stdscr, move_output + 11, 200, "[");
		ft_print_live_break_down_prev(vm, move_output + 11, 201);
	}
}

void		draw_data(t_vm *vm, t_player *pl)
{
	int move_output;

	move_output = vm->pl_index * 4 + 4;
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	(vm->play) ? init_pair(42, COLOR_GREEN, 0) : init_pair(42, COLOR_RED, 0);
	attron(COLOR_PAIR(42));
	mvwprintw(stdscr, 2, 200, (!vm->play) ? "** PAUSED **" : "** RUNNING **");
	attroff(COLOR_PAIR(42));
	attron(COLOR_PAIR(6));
	mvwprintw(stdscr, 7, 200, "Cycle : %d", vm->cycles);
	mvwprintw(stdscr, 9, 200, "Processes : %d", vm->processes);
	mvwprintw(stdscr, move_output + 14, 200, "CYCLE_TO_DIE : %d",
			vm->cycle_to_die);
	mvwprintw(stdscr, move_output + 16, 200, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvwprintw(stdscr, move_output + 18, 200, "NBR_LIVE : %d", NBR_LIVE);
	mvwprintw(stdscr, move_output + 20, 200, "MAX_CHECKS : %d", MAX_CHECKS);
	mvwprintw(stdscr, move_output + 7, 202,
			"Live breakdown for current period :");
	ft_draw_data_2(vm, pl, move_output);
	attroff(COLOR_PAIR(6));
}

void		key_function(t_vm *vm)
{
	int			c;
	const char	*speed_s[] = {"-4x", "-2x", "1x", "2x", "4x"};

	noecho();
	c = wgetch(stdscr);
	if (c == 32)
		vm->play = (vm->play == 0) ? 1 : 0;
	mvwprintw(stdscr, 5, 200, "Speed : %s ", speed_s[vm->speed]);
	if (c == 43 && vm->speed < 4)
		vm->speed++;
	if (c == 45 && vm->speed != 0)
		vm->speed--;
	if (c == 27)
	{
		endwin();
		exit(0);
	}
}
