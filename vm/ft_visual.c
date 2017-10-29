/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:23:04 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:23:06 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

int			ft_get_number_of_pl(t_player *pl, t_player *find)
{
	int i;

	i = 0;
	while (pl)
	{
		if (pl == find)
			break ;
		i++;
		pl = pl->next;
	}
	return (i);
}

void		ft_print_live_break_down(t_vm *vm, int y, int x)
{
	int i;
	int pair;

	i = 0;
	pair = 0;
	while (i < 50)
	{
		if (vm->br_down_color[pair] < 0.5)
		{
			if (pair < vm->pl_index)
			{
				pair++;
				continue;
			}
		}
		attron(COLOR_PAIR(pair + 1));
		mvwprintw(stdscr, y, x, "-");
		vm->br_down_color[pair] -= 1.0;
		i++;
		x++;
	}
	attron(COLOR_PAIR(6));
	mvwprintw(stdscr, y, x, "]");
}

void		ft_print_live_break_down_prev(t_vm *vm, int y, int x)
{
	int		i;
	int		index;
	int		pair;
	float	temp;

	i = 0;
	index = 0;
	temp = vm->prev_br_down_color[index];
	pair = 1;
	while (i < 50)
	{
		if (temp < 0.5 && pair < vm->pl_index)
		{
			pair++;
			index++;
			temp = vm->prev_br_down_color[index];
			continue;
		}
		attron(COLOR_PAIR(pair));
		mvwprintw(stdscr, y, x++, "-");
		temp -= 1.0;
		i++;
	}
	attron(COLOR_PAIR(6));
	mvwprintw(stdscr, y, x, "]");
}

void		ft_init_color_map(t_vm *vm, t_process *pr)
{
	t_process	*proc;
	int			start;
	int			end;
	int			color_pair;

	start = 0;
	while (start < MEM_SIZE)
	{
		vm->color_map[start] = 0;
		start++;
	}
	proc = pr;
	color_pair = vm->pl_index;
	while (proc)
	{
		start = proc->pc;
		end = start + proc->pl_belongs->prog_size_nb;
		while (start < end)
		{
			vm->color_map[start] = color_pair;
			start++;
		}
		color_pair--;
		proc = proc->next;
	}
}

void		ft_visual(t_vm *vm, t_player *head, t_process *proc)
{
	const useconds_t speed_mode[] = {160000, 80000, 10000, 2500, 0};

	draw_memmory(vm, proc);
	draw_data(vm, head);
	draw_players(head);
	draw_menu();
	attroff(COLOR_PAIR(6));
	key_function(vm);
	usleep(speed_mode[vm->speed]);
	if (vm->cycle_to_die < 0 || (proc == NULL))
		ft_print_champ(vm, head);
}
