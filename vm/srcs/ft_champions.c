/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_champions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:11:45 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:11:47 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void		ft_player_short_check(t_player *pl, ssize_t bytes, char *name)
{
	unsigned int mg;

	if (bytes <= 0)
	{
		ft_printf("Error: File %s is too small to be a champion\n", name);
		exit(0);
	}
	mg = ft_convert_hex_to_dec(pl->magic);
	if (mg != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Error: File %s has an invalid header\n", name);
		exit(0);
	}
}

void		ft_check_prog_size(t_player *pl, char *name)
{
	pl->prog_size_nb = ft_convert_hex_to_dec(pl->prog_size);
	if (pl->prog_size_nb > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s is too big to be a champion\n", name);
		exit(0);
	}
}

void		ft_finish_creation(t_vm *vm, t_player *new_one, ssize_t rb, int i)
{
	new_one->inctructions[CHAMP_MAX_SIZE] = '\0';
	ft_player_short_check(new_one, rb, vm->name_files[i]);
	new_one->last_live = 0;
	new_one->live_in_curr_period = 0;
	new_one->nb_pl = (-1 * vm->number[i]);
}

t_player	*ft_create_player(int fd, t_vm *vm, int i)
{
	t_player	*new_one;
	ssize_t		read_bytes;

	new_one = (t_player *)malloc(sizeof(t_player));
	new_one->next = NULL;
	read_bytes = read(fd, new_one->magic, 4);
	ft_player_short_check(new_one, read_bytes, vm->name_files[i]);
	read_bytes = read(fd, new_one->name, PROG_NAME_LENGTH);
	new_one->name[PROG_NAME_LENGTH] = '\0';
	ft_player_short_check(new_one, read_bytes, vm->name_files[i]);
	lseek(fd, 4, 1);
	read_bytes = read(fd, new_one->prog_size, 4);
	ft_check_prog_size(new_one, vm->name_files[i]);
	ft_player_short_check(new_one, read_bytes, vm->name_files[i]);
	read_bytes = read(fd, new_one->comment, COMMENT_LENGTH);
	new_one->comment[COMMENT_LENGTH] = '\0';
	ft_player_short_check(new_one, read_bytes, vm->name_files[i]);
	lseek(fd, 4, 1);
	read_bytes = read(fd, new_one->inctructions, CHAMP_MAX_SIZE);
	if ((read_bytes != new_one->prog_size_nb) || (read_bytes > CHAMP_MAX_SIZE))
		ft_size_error(new_one->name);
	ft_finish_creation(vm, new_one, read_bytes, i);
	close(fd);
	return (new_one);
}

void		ft_add_player(t_player **head, int fd, t_vm *vm, int i)
{
	t_player *new_one;
	t_player *temp;

	new_one = ft_create_player(fd, vm, i);
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_one;
}
