/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:13:46 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:13:47 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

int				ft_get_lldi_args(t_vm *vm, t_process *p, short *addr)
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
		*addr += (short)ft_t_ind_process_long(vm, p);
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

unsigned int	ft_finish_lldi(t_vm *vm, t_process *p, short *addr)
{
	unsigned int	res;
	short			prev_i;

	*addr += p->pc;
	*addr %= (short)MEM_SIZE;
	if (*addr < 0)
		*addr += (short)MEM_SIZE;
	prev_i = p->index;
	p->index = *addr;
	res = ft_get_value(vm, p, REG_SIZE);
	p->index = prev_i;
	return (res);
}

void			ft_lldi(t_vm *vm, t_process *p)
{
	short			addr;
	unsigned int	res;
	int				final_reg;

	if (p->correct_args)
	{
		addr = 0;
		if (!ft_get_lldi_args(vm, p, &addr))
			return ;
		final_reg = ft_t_reg_process(vm, p);
		if (!ft_check_regs(vm, p, final_reg))
			return ;
		res = ft_finish_lldi(vm, p, &addr);
		p->registers[final_reg] = res;
		if (res == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
	else
		ft_process_inval_args(vm, p);
	ft_clear_args(p);
}
