/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:10:56 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:10:59 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void				ft_add(t_vm *vm, t_process *proc)
{
	unsigned int	sum;
	int				reg_1;
	int				reg_2;
	int				reg_3;

	if (proc->correct_args)
	{
		reg_1 = ft_t_reg_process(vm, proc);
		reg_2 = ft_t_reg_process(vm, proc);
		reg_3 = ft_t_reg_process(vm, proc);
		if (!ft_check_regs(vm, proc, reg_1) || !ft_check_regs(vm, proc, reg_2)
			|| !ft_check_regs(vm, proc, reg_3))
			return ;
		sum = 0;
		sum += proc->registers[reg_1];
		sum += proc->registers[reg_2];
		proc->registers[reg_3] = sum;
		if (sum == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	else
		ft_process_inval_args(vm, proc);
	ft_clear_args(proc);
}
