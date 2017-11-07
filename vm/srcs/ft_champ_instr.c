/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_champ_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:20:57 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 19:20:58 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.h"

unsigned int	ft_get_value(t_vm *vm, t_process *pr, int label_size)
{
	unsigned int	tmp;
	char			*hex_string;
	char			*ch_tmp;

	hex_string = ft_strnew(0);
	while (label_size > 0)
	{
		tmp = vm->memory[pr->index];
		if (tmp == 0)
			hex_string = ft_join(hex_string, "00");
		else
		{
			if (tmp >= 1 && tmp <= 15)
				hex_string = ft_join(hex_string, "0");
			ch_tmp = ft_itoa_base(tmp);
			hex_string = ft_join(hex_string, ch_tmp);
			free(ch_tmp);
		}
		pr->index++;
		pr->index == MEM_SIZE ? pr->index = 0 : 0;
		label_size--;
	}
	tmp = ft_convert_dec(hex_string);
	free(hex_string);
	return (tmp);
}

void			ft_check_pl_numbers(t_player *pl)
{
	t_player *cur;
	t_player *after;

	cur = pl;
	while (cur)
	{
		after = cur->next;
		while (after)
		{
			if (cur->nb_pl == after->nb_pl)
			{
				ft_printf("Error: equal numbers of champion %s and %s\n",
						cur->name, after->name);
				exit(0);
			}
			after = after->next;
		}
		cur = cur->next;
	}
}

void			ft_read_champions(t_vm *vm, t_player **head)
{
	int fd;
	int i;

	i = 0;
	while (i < vm->pl_index)
	{
		fd = open(vm->name_files[i], O_RDONLY);
		if (fd == -1 || !ft_check_file_name(vm->name_files[i]))
		{
			ft_printf("Can't read source file %s\n", vm->name_files[i]);
			exit(0);
		}
		if (*head == NULL)
		{
			*head = ft_create_player(fd, vm, i);
			vm->head_pl = *head;
		}
		else
			ft_add_player(head, fd, vm, i);
		i++;
		close(fd);
	}
	ft_check_pl_numbers(*head);
}
