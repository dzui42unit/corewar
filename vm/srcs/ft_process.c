/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:25:45 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:25:46 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

int			ft_check_regs(t_vm *vm, t_process *proc, int reg_nb)
{
	if (reg_nb >= 0 && reg_nb < REG_NUMBER)
		return (1);
	proc->index = proc->pc;
	proc->index++;
	if (proc->index == MEM_SIZE)
		proc->index = 0;
	if (g_tab[proc->instr_nb].codage_oct)
	{
		proc->index++;
		if (proc->index == MEM_SIZE)
			proc->index = 0;
	}
	ft_process_inval_args(vm, proc);
	proc->pc = proc->index;
	ft_clear_args(proc);
	proc->correct_args = 1;
	return (0);
}

void		ft_finish_proc_creation(t_process *new_one)
{
	int i;

	i = 0;
	new_one->arg_1 = 0;
	new_one->arg_2 = 0;
	new_one->arg_3 = 0;
	while (i < 3)
	{
		new_one->args[i] = 0;
		i++;
	}
	new_one->registers[0] = new_one->pl_belongs->nb_pl;
	i = 1;
	while (i < REG_NUMBER)
	{
		new_one->registers[i] = 0;
		i++;
	}
	new_one->correct_args = 1;
}

t_process	*ft_create_process(t_process *head, t_player *pl, short pc)
{
	t_process		*new_one;
	t_process		*start;
	unsigned int	i;

	i = 0;
	start = head;
	while (start)
	{
		start = start->next;
		i++;
	}
	new_one = (t_process *)malloc(sizeof(t_process));
	new_one->pc = pc;
	new_one->carry = 0;
	new_one->index = pc;
	new_one->proc_number = i + 1;
	new_one->pl_belongs = pl;
	new_one->live = 0;
	new_one->cur_cycles = 0;
	new_one->start_command = 0;
	new_one->instr_nb = 0;
	new_one->last_live_ind = -1;
	new_one->next = NULL;
	ft_finish_proc_creation(new_one);
	return (new_one);
}

t_process	*ft_add_process(t_process **head, t_player *pl, short pc)
{
	t_process *new_one;
	t_process *temp;

	temp = *head;
	new_one = ft_create_process(*head, pl, pc);
	*head = new_one;
	new_one->next = temp;
	return (new_one);
}
