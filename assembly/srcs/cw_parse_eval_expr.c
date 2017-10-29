/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_eval_expr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:53:48 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:58:27 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	cw_put_value(t_args *current, char **expr_tab, char flag_type)
{
	if (flag_type != 1)
		current->value1 = cw_lltoi(expr_tab[0]);
	current->code = *expr_tab[1];
	current->value2 = cw_lltoi(expr_tab[2]);
}

static int	cw_error2(char **expr_tab, char args_nbr, int line_nbr)
{
	if (ft_strlen(expr_tab[1]) != 1 ||
			(*expr_tab[1] != '+' && *expr_tab[1] != '-' && *expr_tab[1] != '*'
			&& *expr_tab[1] != '/' && *expr_tab[1] != '%'))
	{
		ft_printf("Unauthorised operator in expression - [arg %d] - Line %d "
				"- Authorised operator are +, -, * and /\n",
				args_nbr, line_nbr);
		return (-1);
	}
	if (cw_isnumber_syntax(expr_tab[2], 1) != 1)
	{
		ft_printf("The second value in expression is not a number - [arg %d] "
				"- Line %d\n", args_nbr, line_nbr);
		return (-1);
	}
	return (0);
}

static int	cw_check_tab_length(char **expr_tab, char args_nbr, int line_nbr)
{
	if (cw_strtab_len(expr_tab) != 3)
	{
		ft_printf("Unauthorised expression : [arg %d] - Line %d\n"
				"-> Maximum operation (+,-,*,/,%%) between a "
				"label/number and a number\n"
				"	Example: %%100 + 25\n", args_nbr, line_nbr);
		return (-1);
	}
	return (0);
}

int			cw_parse_eval_expr_tag(t_args *current, char args_nbr,
											int line_nbr, t_instr *check_tag)
{
	char	**expr_tab;
	char	*content;
	char	*tag;

	content = (current->type < 3) ? current->content + 2 : current->content + 1;
	if (!(expr_tab = ft_strsplit(content, ' ')))
		return (cw_free_and_exit_expr_tab(expr_tab));
	if (cw_check_tab_length(expr_tab, args_nbr, line_nbr) == -1)
		return (cw_free_and_exit_expr_tab(expr_tab));
	if (cw_exist_label(check_tag, expr_tab[0]) == 0)
	{
		ft_printf("Undefined label [arg %d] - Line %d\n", args_nbr, line_nbr);
		return (cw_free_and_exit_expr_tab(expr_tab));
	}
	tag = content;
	tag[ft_charindex(content, ' ')] = '\0';
	current->tag = tag;
	if (cw_error2(expr_tab, args_nbr, line_nbr) == -1)
		return (cw_free_and_exit_expr_tab(expr_tab));
	cw_put_value(current, expr_tab, 1);
	cw_strtab_free(expr_tab);
	return (0);
}

int			cw_parse_eval_expr(t_args *current, char args_nbr, int line_nbr)
{
	char	**expr_tab;
	char	*content;

	content = (current->type < 3) ? current->content + 1 : current->content;
	if (!(expr_tab = ft_strsplit(content, ' ')))
		return (cw_free_and_exit_expr_tab(expr_tab));
	if (cw_check_tab_length(expr_tab, args_nbr, line_nbr) == -1)
		return (cw_free_and_exit_expr_tab(expr_tab));
	if (cw_isnumber_syntax(expr_tab[0], 1) != 1)
	{
		ft_printf("The first value in expression is not a number/label - "
				"[arg %d] - Line %d\n", args_nbr, line_nbr);
		return (cw_free_and_exit_expr_tab(expr_tab));
	}
	if (cw_error2(expr_tab, args_nbr, line_nbr) == -1)
		return (cw_free_and_exit_expr_tab(expr_tab));
	cw_put_value(current, expr_tab, 0);
	cw_strtab_free(expr_tab);
	return (0);
}
