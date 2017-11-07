/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:22:21 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:22:27 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_count_target(t_vm *vm, t_process *proc, short *target)
{
	*target = (short)ft_get_value(vm, proc, 2);
	*target %= (short)IDX_MOD;
	*target += proc->pc;
	*target %= (short)MEM_SIZE;
	if (*target < 0)
		*target += (short)MEM_SIZE;
}

void		ft_st(t_vm *vm, t_process *proc)
{
	int		init_reg;
	short	target;

	if (proc->correct_args)
	{
		init_reg = ft_t_reg_process(vm, proc);
		if (!ft_check_regs(vm, proc, init_reg))
			return ;
		if (proc->args[1] == T_IND)
		{
			ft_count_target(vm, proc, &target);
			ft_copy_value(vm, proc, target, proc->registers[init_reg]);
		}
		if (proc->args[1] == T_REG)
		{
			target = (short)ft_t_reg_process(vm, proc);
			if (!ft_check_regs(vm, proc, target))
				return ;
			proc->registers[target] = proc->registers[init_reg];
		}
	}
	else
		ft_process_inval_args(vm, proc);
	ft_clear_args(proc);
}
