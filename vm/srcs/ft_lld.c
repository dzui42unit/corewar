/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:13:33 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:13:34 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

unsigned int		ft_t_ind_process_long(t_vm *vm, t_process *pr)
{
	int				prev_i;
	unsigned int	res;
	short			t_ind_value;

	t_ind_value = (short)ft_get_value(vm, pr, 2);
	prev_i = pr->index;
	pr->index = (short)(((pr->pc + t_ind_value)) % MEM_SIZE);
	if (pr->index < 0)
		pr->index += (short)MEM_SIZE;
	res = ft_get_value(vm, pr, 2);
	pr->index = (short)prev_i;
	return (res);
}

void				ft_lld(t_vm *vm, t_process *p)
{
	int				target_reg;
	unsigned int	res;

	if (p->correct_args)
	{
		if (p->args[0] == T_DIR)
			res = (short)ft_t_dir_process(vm, p,
										g_tab[p->instr_nb].label_size);
		if (p->args[0] == T_IND)
			res = (short)ft_t_ind_process_long(vm, p);
		target_reg = ft_t_reg_process(vm, p);
		if (!ft_check_regs(vm, p, target_reg))
			return ;
		p->registers[target_reg] = res;
		if (res == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
	else
		ft_process_inval_args(vm, p);
	ft_clear_args(p);
}
