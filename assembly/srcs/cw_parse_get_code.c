/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_get_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 12:00:39 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:01:41 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_parse_get_code : Check the validity and return the value of the code
** from args_line of t_instr.
*/

static int	cw_pick_up(char **content, char *line, char analyze, int (*type)())
{
	if ((*type)(analyze) == 1)
	{
		if (!(*content = ft_strndup(line, ft_charindex(line, analyze))))
			return (-1);
		return (1);
	}
	return (0);
}

static int	cw_is_separator(int c)
{
	if (c == DIRECT_CHAR || c == '-')
		return (1);
	else if (ft_isdigit(c))
		return (1);
	else if (ft_isspace(c))
		return (1);
	return (0);
}

static int	cw_pick_code(char *analyze, char **content, int *i)
{
	int		out;

	if ((out = cw_pick_up(&(*content), analyze, analyze[*i],
					cw_is_separator)) == -1)
		return (-1);
	if (out == 1)
		return (1);
	return (0);
}

static int	cw_identify_code(char *code)
{
	int		i;

	i = 1;
	if (!code)
		return (-10);
	while (ft_strcmp(g_op_tab[i].name, code) != 0)
	{
		i++;
		if (i > 16)
			return (-10);
	}
	return (i);
}

int			cw_parse_get_code(char *analyze, char **code_name)
{
	int		i;
	int		out;

	i = 0;
	while (analyze[i] != '\0')
	{
		if ((out = cw_pick_code(analyze, &(*code_name), &i)) == -1)
			return (-1);
		if (out == 1)
			break ;
		i++;
	}
	return (cw_identify_code(*code_name));
}
