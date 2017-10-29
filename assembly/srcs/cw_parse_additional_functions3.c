/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_additional_functions3.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:42:42 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:42:43 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*cw_strjoin_and_free(char *s1, char *s2)
{
	char *tmp;

	tmp = s1;
	if (!(s1 = ft_strjoin(tmp, s2)))
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	ft_strdel(&tmp);
	return (s1);
}

int		cw_strindex(const char *s, const char *to_check)
{
	char *ptr;

	ptr = ft_strstr(s, to_check);
	if (ptr == NULL)
		return (-1);
	else
		return (ptr - s);
}

int		cw_free_and_exit_expr_tab(char **expr_tab)
{
	cw_strtab_free(expr_tab);
	return (-1);
}

size_t	cw_strtab_len(char **tab)
{
	size_t	count;

	count = 0;
	if (tab == NULL)
		return (0);
	while (tab[count] != NULL)
		count++;
	return (count);
}

int		cw_exist_label(t_instr *instr_list, char *tag_to_check)
{
	t_instr *temp_instr;

	temp_instr = instr_list;
	while (temp_instr != NULL)
	{
		if (temp_instr->tag_name != NULL)
		{
			if (ft_strcmp(temp_instr->tag_name, tag_to_check) == 0)
				return (1);
		}
		temp_instr = temp_instr->next;
	}
	return (0);
}
