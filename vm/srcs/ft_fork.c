/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:12:00 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:12:02 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_set_regs(t_process *new_one, t_process *proc)
{
	int i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new_one->registers[i] = proc->registers[i];
		i++;
	}
}

void		ft_fork(t_vm *vm, t_process *p, t_process **head_proc)
{
	short		addr;
	t_process	*new_one;
	t_process	*temp;

	addr = (short)ft_t_dir_process(vm, p, 2);
	addr %= (short)IDX_MOD;
	addr += p->pc;
	addr %= (short)MEM_SIZE;
	if (addr < 0)
		addr += (short)MEM_SIZE;
	new_one = ft_create_process(*head_proc, p->pl_belongs, addr);
	new_one->carry = p->carry;
	temp = *head_proc;
	new_one->next = temp;
	*head_proc = new_one;
	vm->processes++;
	new_one->correct_args = 1;
	new_one->start_command = 0;
	new_one->live = p->live;
	ft_set_regs(new_one, p);
	ft_clear_args(p);
}
