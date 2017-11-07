/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:11:14 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:11:15 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_print_char(t_vm *vm, unsigned char ch)
{
	if (!vm->visual)
	{
		write(1, "Aff: ", 5);
		if (ft_isprint(ch))
		{
			write(1, &ch, 1);
			write(1, "\n", 1);
		}
		else
			write(1, "\n", 1);
	}
	if (vm->visual)
	{
		if (ft_isprint(ch))
			mvwprintw(stdscr, 67, 350, "Aff: %c", ch);
		else
			mvwprintw(stdscr, 67, 350, "Aff: ?");
	}
}

void		ft_aff(t_vm *vm, t_process *proc)
{
	int				reg;
	unsigned char	ch;

	if (proc->correct_args)
	{
		reg = ft_t_reg_process(vm, proc);
		if (!ft_check_regs(vm, proc, reg))
			return ;
		ch = (unsigned char)proc->registers[reg];
		ch %= 256;
		ft_print_char(vm, ch);
	}
	ft_clear_args(proc);
}
