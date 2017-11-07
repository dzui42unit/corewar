/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:11:32 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 19:11:45 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

void		draw_vertical_border(int x)
{
	int i;

	i = 68;
	while (--i)
		mvwprintw(stdscr, i, x, "*");
}

void		draw_horizontal_border(int y)
{
	int i;

	i = 351;
	while (--i >= 0)
		mvwprintw(stdscr, y, i, "*");
}

void		draw_frame(void)
{
	init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
	attron(COLOR_PAIR(7));
	draw_vertical_border(0);
	draw_vertical_border(350);
	draw_vertical_border(197);
	draw_horizontal_border(0);
	draw_horizontal_border(67);
	attron(COLOR_PAIR(1));
}

void		draw_player_info(t_player *pl, int num)
{
	static int y_arr[] = {11, 15, 19, 23};

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(66, COLOR_BLACK, COLOR_WHITE);
	init_pair(21, COLOR_BLACK, COLOR_GREEN);
	init_pair(22, COLOR_BLACK, COLOR_BLUE);
	init_pair(23, COLOR_BLACK, COLOR_RED);
	init_pair(24, COLOR_BLACK, COLOR_CYAN);
	init_pair(31, COLOR_WHITE, COLOR_GREEN);
	init_pair(32, COLOR_WHITE, COLOR_BLUE);
	init_pair(33, COLOR_WHITE, COLOR_RED);
	init_pair(34, COLOR_WHITE, COLOR_CYAN);
	attron(COLOR_PAIR(num));
	mvwprintw(stdscr, y_arr[num - 1], 200, "Player: %d %s",
			pl->nb_pl, pl->name);
	attroff(COLOR_PAIR(num));
	mvwprintw(stdscr, y_arr[num - 1] + 1, 202, "Last live :%24d",
			pl->last_live);
	mvwprintw(stdscr, y_arr[num - 1] + 2, 202,
			"Last live in current period :%6d", pl->live_in_curr_period);
}
