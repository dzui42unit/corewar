/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:12:33 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:12:35 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_ld(t_vm *vm, t_process *proc)
{
	int				target_reg;
	unsigned int	res;

	if (proc->correct_args)
	{
		if (proc->args[0] == T_DIR)
			res = ft_t_dir_process(vm, proc, g_tab[proc->instr_nb].label_size);
		if (proc->args[0] == T_IND)
			res = ft_t_ind_process(vm, proc);
		target_reg = ft_t_reg_process(vm, proc);
		if (!ft_check_regs(vm, proc, target_reg))
			return ;
		proc->registers[target_reg] = res;
		if (res == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	else
		ft_process_inval_args(vm, proc);
	ft_clear_args(proc);
}
