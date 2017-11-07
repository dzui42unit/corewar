/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:11:24 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:11:26 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

int			ft_get_and_args(t_vm *vm, t_process *p)
{
	int reg;

	if (p->args[0] == T_REG)
	{
		reg = ft_t_reg_process(vm, p);
		if (!ft_check_regs(vm, p, reg))
			return (0);
		p->arg_1 = p->registers[reg];
	}
	if (p->args[0] == T_DIR)
		p->arg_1 = ft_t_dir_process(vm, p, g_tab[p->instr_nb].label_size);
	if (p->args[0] == T_IND)
		p->arg_1 = ft_t_ind_process(vm, p);
	if (p->args[1] == T_REG)
	{
		reg = ft_t_reg_process(vm, p);
		if (!ft_check_regs(vm, p, reg))
			return (0);
		p->arg_2 = p->registers[reg];
	}
	if (p->args[1] == T_DIR)
		p->arg_2 = ft_t_dir_process(vm, p, g_tab[p->instr_nb].label_size);
	if (p->args[1] == T_IND)
		p->arg_2 = ft_t_ind_process(vm, p);
	return (1);
}

void		ft_and(t_vm *vm, t_process *proc)
{
	int				final_reg;
	unsigned int	res;

	if (proc->correct_args)
	{
		if (!ft_get_and_args(vm, proc))
			return ;
		final_reg = ft_t_reg_process(vm, proc);
		if (!ft_check_regs(vm, proc, final_reg))
			return ;
		res = (proc->arg_1 & proc->arg_2);
		proc->registers[final_reg] = res;
		if (res == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	else
		ft_process_inval_args(vm, proc);
	ft_clear_args(proc);
}
