/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_instr_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:21:54 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:21:55 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

void			ft_size_error(char *ch_name)
{
	ft_printf("Error: File %s has a code size ", ch_name);
	ft_printf("that differ from what its header says\n");
	exit(0);
}

unsigned int	ft_t_reg_process(t_vm *vm, t_process *pr)
{
	unsigned int number;

	number = vm->memory[pr->index];
	pr->index++;
	if (pr->index == MEM_SIZE)
		pr->index = 0;
	return (number - 1);
}

unsigned int	ft_t_ind_process(t_vm *vm, t_process *pr)
{
	int				prev_i;
	unsigned int	res;
	short			t_ind_value;

	t_ind_value = (short)ft_get_value(vm, pr, 2);
	t_ind_value %= (short)IDX_MOD;
	prev_i = pr->index;
	pr->index = (short)(((pr->pc + t_ind_value)) % MEM_SIZE);
	if (pr->index < 0)
		pr->index += MEM_SIZE;
	res = ft_get_value(vm, pr, 4);
	pr->index = (short)prev_i;
	return (res);
}

unsigned int	ft_t_dir_process(t_vm *vm, t_process *pr, int label)
{
	unsigned int t_dir_value;

	t_dir_value = ft_get_value(vm, pr, label);
	return (t_dir_value);
}

void			ft_process_inval_args(t_vm *vm, t_process *pr)
{
	int i;

	i = 0;
	while (i < g_tab[pr->instr_nb].args_nb)
	{
		if (pr->args[i] == T_REG)
			ft_t_reg_process(vm, pr);
		if (pr->args[i] == T_IND)
			ft_t_ind_process(vm, pr);
		if (pr->args[i] == T_DIR)
		{
			if (g_tab[pr->instr_nb].label_size)
				ft_t_dir_process(vm, pr, g_tab[pr->instr_nb].label_size);
			else
				ft_t_dir_process(vm, pr, 4);
		}
		i++;
	}
	pr->pc = pr->index;
}
