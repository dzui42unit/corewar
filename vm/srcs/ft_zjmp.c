/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:23:24 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:23:25 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_zjmp(t_vm *vm, t_process *p)
{
	short target;

	target = (short)ft_t_dir_process(vm, p, g_tab[p->instr_nb].label_size);
	if (p->carry == 1)
	{
		target %= (short)IDX_MOD;
		p->pc += target;
		p->pc %= (short)MEM_SIZE;
		if (p->pc < 0)
			p->pc += (short)MEM_SIZE;
		p->index = p->pc;
	}
	p->correct_args = 1;
	ft_clear_args(p);
}
