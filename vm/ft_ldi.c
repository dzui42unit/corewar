/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:12:45 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:12:47 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_finish_ldi(t_vm *vm, t_process *proc, short addr, int fr)
{
	short			prev_i;
	unsigned int	res;

	addr %= (short)IDX_MOD;
	addr += proc->pc;
	addr %= (short)MEM_SIZE;
	if (addr < 0)
		addr += (short)MEM_SIZE;
	prev_i = proc->index;
	proc->index = addr;
	res = ft_get_value(vm, proc, REG_SIZE);
	proc->index = prev_i;
	proc->registers[fr] = res;
}

int			ft_read_args(t_vm *vm, t_process *p, short *addr)
{
	int arg;

	if (p->args[0] == T_REG)
	{
		arg = ft_t_reg_process(vm, p);
		if (!(ft_check_regs(vm, p, arg)))
			return (0);
		*addr += (short)p->registers[arg];
	}
	if (p->args[0] == T_DIR)
		*addr += (short)ft_t_dir_process(vm, p, g_tab[p->instr_nb].label_size);
	if (p->args[0] == T_IND)
		*addr += (short)ft_t_ind_process(vm, p);
	if (p->args[1] == T_REG)
	{
		arg = ft_t_reg_process(vm, p);
		if (!(ft_check_regs(vm, p, arg)))
			return (0);
		*addr += (short)p->registers[arg];
	}
	if (p->args[1] == T_DIR)
		*addr += (short)ft_t_dir_process(vm, p, g_tab[p->instr_nb].label_size);
	return (1);
}

void		ft_ldi(t_vm *vm, t_process *p)
{
	short	addr;
	int		final_reg;

	if (p->correct_args)
	{
		addr = 0;
		if (!ft_read_args(vm, p, &addr))
			return ;
		final_reg = ft_t_reg_process(vm, p);
		if (!ft_check_regs(vm, p, final_reg))
			return ;
		ft_finish_ldi(vm, p, addr, final_reg);
	}
	else
		ft_process_inval_args(vm, p);
	ft_clear_args(p);
}
