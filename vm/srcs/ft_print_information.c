/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_information.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:21:40 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:21:41 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void	ft_print_players(t_player *players)
{
	t_player *cur;

	cur = players;
	ft_printf("Introducing contestants...\n");
	while (cur)
	{
		ft_printf("* Player %ld, weighing %u bytes, \"%s\" (\"%s\") !\n",
				-1 * cur->nb_pl, cur->prog_size_nb, cur->name, cur->comment);
		cur = cur->next;
	}
}

void	ft_print_memory(t_vm *vm)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("0x%.4x : ", 0);
	while (i < MEM_SIZE)
	{
		if (j % 64 == 0 && j != 0)
		{
			ft_printf("\n");
			ft_printf("0x%.4x : ", j);
		}
		j++;
		ft_printf("%.2x ", vm->memory[i]);
		i++;
	}
	ft_printf("\n");
}
