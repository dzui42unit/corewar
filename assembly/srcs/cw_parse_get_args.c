/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_get_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:58:54 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 13:37:37 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_parse_get_args : Check and add the argument(s) of the args_line (t_instr)
** in the linked list *args_list (t_instr) for each instruction.
*/

static t_args	*cw_initialize_argument(char *content)
{
	t_args	*new_argument;

	if (!(new_argument = (t_args*)malloc(sizeof(t_args))))
		return (NULL);
	new_argument->content = NULL;
	new_argument->type = 0;
	new_argument->t_arg = 0;
	new_argument->value1 = 0;
	new_argument->value2 = 0;
	new_argument->code = 0;
	new_argument->tag = NULL;
	if (content != NULL && *content != '\0')
	{
		if (!(new_argument->content = ft_strdup(content)))
			return (NULL);
	}
	return (new_argument);
}

static int		cw_add_argument(t_args **list_head, char *content)
{
	t_args	*new_argument;

	new_argument = *list_head;
	if (*list_head == NULL)
	{
		if (!(*list_head = cw_initialize_argument(content)))
			return (-1);
		(*list_head)->next = NULL;
	}
	else
	{
		while (new_argument->next != NULL)
			new_argument = new_argument->next;
		if (!(new_argument->next = cw_initialize_argument(content)))
			return (-1);
		new_argument->next->next = NULL;
	}
	return (0);
}

static int		cw_push_arg(t_args **args_list, char **args_tab)
{
	int		i;

	i = 0;
	while (args_tab[i] != NULL)
	{
		if (cw_add_argument(&(*args_list), args_tab[i]) == -1)
		{
			cw_strtab_free(args_tab);
			return (-1);
		}
		i++;
	}
	return (0);
}

static int		cw_check_args_nbr(char **args_tab, int code, char line_nbr)
{
	int		args_nbr;

	args_nbr = 0;
	while (args_tab[args_nbr] != NULL)
		args_nbr++;
	if (args_nbr != g_op_tab[code].nb_args)
	{
		ft_printf("Invalid parameter number for the instruction '%s' - expected"
				"%d, have %d - Line %d\n", g_op_tab[code].name,
				g_op_tab[code].nb_args, args_nbr, line_nbr);
		cw_strtab_free(args_tab);
		return (-1);
	}
	return (0);
}

int				cw_parse_get_args(t_instr **inst_list)
{
	t_instr	*current;
	char	**args_tab;

	current = *inst_list;
	while (current != NULL)
	{
		if (current->args_line)
		{
			if (!(args_tab = ft_strsplit(current->args_line, SEPARATOR_CHAR)))
				return (-1);
			if (cw_check_args_nbr(args_tab, current->code,
						current->line_nbr) == -1)
				return (-1);
			if (cw_push_arg(&(current->args_list), args_tab) == -1)
				return (-1);
			cw_strtab_free(args_tab);
		}
		current = current->next;
	}
	return (0);
}
