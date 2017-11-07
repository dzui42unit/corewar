/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:22:31 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:22:33 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

int			ft_get_sti_args(t_vm *vm, t_process *proc, short *address)
{
	int reg;

	if (proc->args[1] == T_REG)
	{
		reg = ft_t_reg_process(vm, proc);
		if (!ft_check_regs(vm, proc, reg))
			return (0);
		*address += (short)proc->registers[reg];
	}
	if (proc->args[1] == T_DIR)
		*address += (short)ft_t_dir_process(vm, proc,
											g_tab[proc->instr_nb].label_size);
	if (proc->args[1] == T_IND)
		*address += (short)ft_t_ind_process(vm, proc);
	if (proc->args[2] == T_REG)
	{
		reg = ft_t_reg_process(vm, proc);
		if (!ft_check_regs(vm, proc, reg))
			return (0);
		*address += (short)proc->registers[reg];
	}
	if (proc->args[2] == T_DIR)
		*address += (short)ft_t_dir_process(vm, proc,
											g_tab[proc->instr_nb].label_size);
	return (1);
}

void		ft_sti(t_vm *vm, t_process *proc)
{
	int		first_reg;
	short	address;

	if (proc->correct_args)
	{
		address = 0;
		first_reg = ft_t_reg_process(vm, proc);
		if (!ft_check_regs(vm, proc, first_reg))
			return ;
		if (!ft_get_sti_args(vm, proc, &address))
			return ;
		address %= (short)IDX_MOD;
		address += proc->pc;
		address %= (short)MEM_SIZE;
		if (address < 0)
			address += (short)MEM_SIZE;
		ft_copy_value(vm, proc, address, proc->registers[first_reg]);
	}
	else
		ft_process_inval_args(vm, proc);
	ft_clear_args(proc);
}
