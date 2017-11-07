/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:26:23 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:26:25 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void			ft_get_arguments(t_process *pr, int nb)
{
	int i;

	pr->args[0] = nb >> 6;
	pr->args[1] = (nb >> 4) & 3;
	pr->args[2] = (nb >> 2) & 3;
	pr->index++;
	if (pr->index == MEM_SIZE)
		pr->index = 0;
	i = 0;
	while (i < g_tab[pr->instr_nb].args_nb)
	{
		if (pr->args[i] == 3)
			pr->args[i]++;
		i++;
	}
	i = 0;
	while (i < g_tab[pr->instr_nb].args_nb)
	{
		if (!(pr->args[i] & g_tab[pr->instr_nb].args[i]))
			pr->correct_args = 0;
		i++;
	}
}

void			ft_choose_instr_2(t_vm *vm,
								t_process *proc, t_process **head)
{
	if (ft_strequ("ldi", g_tab[proc->instr_nb].name))
		ft_ldi(vm, proc);
	if (ft_strequ("fork", g_tab[proc->instr_nb].name))
		ft_fork(vm, proc, head);
	if (ft_strequ("lld", g_tab[proc->instr_nb].name))
		ft_lld(vm, proc);
	if (ft_strequ("lfork", g_tab[proc->instr_nb].name))
		ft_lfork(vm, proc, head);
	if (ft_strequ("lldi", g_tab[proc->instr_nb].name))
		ft_lldi(vm, proc);
	if (ft_strequ("live", g_tab[proc->instr_nb].name))
		ft_live(vm, proc);
	if (ft_strequ("aff", g_tab[proc->instr_nb].name))
		ft_aff(vm, proc);
}

void			ft_choose_instruction(t_vm *vm,
									t_process *proc, t_process **head)
{
	if (ft_strequ("sti", g_tab[proc->instr_nb].name))
		ft_sti(vm, proc);
	if (ft_strequ("and", g_tab[proc->instr_nb].name))
		ft_and(vm, proc);
	if (ft_strequ("or", g_tab[proc->instr_nb].name))
		ft_or(vm, proc);
	if (ft_strequ("xor", g_tab[proc->instr_nb].name))
		ft_xor(vm, proc);
	if (ft_strequ("st", g_tab[proc->instr_nb].name))
		ft_st(vm, proc);
	if (ft_strequ("ld", g_tab[proc->instr_nb].name))
		ft_ld(vm, proc);
	if (ft_strequ("zjmp", g_tab[proc->instr_nb].name))
		ft_zjmp(vm, proc);
	if (ft_strequ("add", g_tab[proc->instr_nb].name))
		ft_add(vm, proc);
	if (ft_strequ("sub", g_tab[proc->instr_nb].name))
		ft_sub(vm, proc);
	ft_choose_instr_2(vm, proc, head);
}

void			ft_finish_instruction(t_process *pr,
									t_vm *vm, t_process **head)
{
	if (pr->start_command)
	{
		if (pr->cur_cycles == 0)
		{
			if (g_tab[pr->instr_nb].codage_oct)
				ft_get_arguments(pr, vm->memory[pr->index]);
			ft_choose_instruction(vm, pr, head);
			if (pr->index == MEM_SIZE)
				pr->index = 0;
			pr->pc = pr->index;
			pr->correct_args = 1;
			pr->start_command = 0;
		}
		else
			pr->cur_cycles--;
	}
}

void			ft_process_instruction(t_process *pr,
									t_vm *vm, t_process **head)
{
	if (!pr->start_command)
	{
		pr->index = pr->pc;
		pr->instr_nb = vm->memory[pr->index] - 1;
		if (pr->instr_nb >= 0 && pr->instr_nb <= 15)
		{
			pr->start_command = 1;
			pr->index++;
			if (pr->index == MEM_SIZE)
				pr->index = 0;
			pr->cur_cycles = g_tab[pr->instr_nb].cycles - 1;
		}
		else
		{
			pr->pc++;
			if (pr->pc == (short)MEM_SIZE)
				pr->pc = 0;
			pr->index = pr->pc;
		}
	}
	ft_finish_instruction(pr, vm, head);
}
