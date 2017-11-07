/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:13:14 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:13:15 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_live(t_vm *vm, t_process *proc)
{
	unsigned int	live_arg;
	t_player		*start;
	int				i;
	const int		pair[] = {190, 290, 390, 490};

	i = 0;
	live_arg = ft_t_dir_process(vm, proc, g_tab[proc->instr_nb].label_size);
	start = vm->head_pl;
	while (start)
	{
		if (live_arg == start->nb_pl)
		{
			vm->iter[proc->pc] = pair[i];
			start->last_live = vm->cycles + 1;
			start->live_in_curr_period++;
			proc->last_live_ind = proc->pc;
		}
		i++;
		start = start->next;
	}
	proc->live = 1;
	ft_clear_args(proc);
}
