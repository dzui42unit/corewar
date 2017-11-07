/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:23:31 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:23:37 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void	draw_menu(void)
{
	mvwprintw(stdscr, 62, 200, "SPACE");
	mvwprintw(stdscr, 62, 217, "to  RUN or to  PAUSE");
	mvwprintw(stdscr, 63, 200, "PLUS");
	mvwprintw(stdscr, 63, 217, "to  ACCELERATE speed");
	mvwprintw(stdscr, 64, 200, "MINUS");
	mvwprintw(stdscr, 64, 217, "to  SLOW DOWN  speed");
	mvwprintw(stdscr, 65, 200, "ESC");
	mvwprintw(stdscr, 65, 217, "to  EXIT the   program");
}

void	ft_print_name(t_vm *vm, t_player *champ, int nb)
{
	if (!vm->visual)
		ft_printf("Contestant %d, \"%s\", has won !\n", nb, champ->name);
	else
	{
		mvwprintw(stdscr, vm->pl_index * 4 + 30, 200, "Contestant %d, ", nb);
		attron(COLOR_PAIR(nb));
		mvwprintw(stdscr, vm->pl_index * 4 + 30, 213, "\"%s\"", champ->name);
		attroff(COLOR_PAIR(nb));
		mvwprintw(stdscr, vm->pl_index * 4 + 30,
			215 + ft_strlen(champ->name), ", has won!");
	}
}

void	ft_print_champ(t_vm *vm, t_player *players)
{
	int			nb;
	uintmax_t	max;
	t_player	*champ;
	t_player	*head;

	max = 0;
	head = players;
	champ = players;
	while (head)
	{
		if (head->last_live >= max)
		{
			champ = head;
			max = head->last_live;
		}
		head = head->next;
	}
	nb = 1;
	head = players;
	while (head != champ)
	{
		nb++;
		head = head->next;
	}
	ft_print_name(vm, champ, nb);
}

void	ft_input_error(void)
{
	ft_printf("Usage: ./corewar [-dump N] <champion1.cor> <...>\n");
	ft_printf("\t-dump N");
	ft_printf("                 : Dumps memory after N cycles then exits\n");
	ft_printf("\t-n N <champion.cor>     : Gives a number to a champion\n");
	ft_printf("\t-v                      : Ncurses output mode\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_player	*players;
	t_vm		vm;
	t_process	*process;

	if (argc == 1)
		ft_input_error();
	players = NULL;
	process = NULL;
	vm.argv = argv;
	ft_set_vm_default_parameters(&vm);
	ft_process_args(&vm);
	ft_read_champions(&vm, &players);
	ft_assign_memory(&vm, players, &process);
	ft_init_color_map(&vm, process);
	vm.head_pl = players;
	if (!vm.visual)
		ft_print_players(players);
	vm.processes = vm.pl_index;
	if (vm.visual)
		ft_run_visual_mode(&vm, &process, players);
	else
		ft_run_normal_mode(&vm, &process, players);
	return (0);
}
