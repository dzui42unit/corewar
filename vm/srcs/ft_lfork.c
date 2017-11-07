/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:13:01 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:13:02 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_lfork(t_vm *vm, t_process *p, t_process **head_proc)
{
	short		addr;
	t_process	*new_one;
	t_process	*temp;

	addr = (short)ft_t_dir_process(vm, p, g_tab[p->instr_nb].label_size);
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
	p->correct_args = 1;
	new_one->start_command = 0;
	new_one->live = p->live;
	ft_set_regs(new_one, p);
	ft_clear_args(p);
}
