/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_check_header.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:50:04 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:53:19 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		cw_error1(char *name, t_parse *parse, const char *str)
{
	int		open_i;

	open_i = ft_charindex(name, '\"');
	if (ft_strn_condition_fulfilling(name, cw_isprint_without_space, open_i))
	{
		ft_printf("Syntax error before content of %s - Line %d\n", str,
														parse->line_nbr);
		exit(-1);
	}
	if (cw_nbr_of_letter_in_str(name, '\"') != 2)
	{
		ft_printf("Syntax error - %s - Line %d\n", str, parse->line_nbr);
		exit(-1);
	}
}

static void		cw_error2(char *name, t_parse *parse, const char *str,
														int content_length)
{
	int		open_i;
	int		close_i;

	open_i = ft_charindex(name, '\"');
	close_i = ft_charindex(name + open_i + 1, '\"');
	if (close_i > content_length)
	{
		ft_printf("Champion %s too long, %d character(s) over the limit (Max"
				"length %d)\n", str, close_i - content_length, content_length);
		exit(-1);
	}
	if (ft_str_condition_fulfilling(name + open_i + close_i + 2,
											cw_isprint_without_space))
	{
		ft_printf("Syntax error after content %s - Line %d\n", str,
											parse->line_nbr);
		exit(-1);
	}
}

static void		cw_cat_name(char const *s, char prog_name[PROG_NAME_LENGTH + 1],
												size_t lenght, const char *str)
{
	int		i;

	if (!s)
		return ;
	if (ft_strcmp(str, NAME_CMD_STRING) == 0)
	{
		i = 0;
		while (lenght)
		{
			prog_name[i] = s[i];
			i++;
			lenght--;
		}
		prog_name[i] = '\0';
	}
}

static void		cw_cat_comment(char const *s, char comment[COMMENT_LENGTH + 1],
												size_t length, const char *str)
{
	int		i;

	if (!s)
		return ;
	if (ft_strcmp(str, COMMENT_CMD_STRING) == 0)
	{
		i = 0;
		while (length)
		{
			comment[i] = s[i];
			i++;
			length--;
		}
		comment[i] = '\0';
	}
}

void			cw_parse_check_header(const char *str,
				unsigned int content_length, t_parse *parse, t_header *header)
{
	char	*name;
	int		open_i;
	int		close_i;

	if (ft_strncmp(parse->free_line, str, ft_strlen(str)) == 0)
	{
		name = parse->free_line + ft_strlen(str);
		open_i = ft_charindex(name, '\"');
		cw_error1(name, parse, str);
		close_i = ft_charindex(name + open_i + 1, '\"');
		cw_error2(name, parse, str, content_length);
		cw_cat_name(name + open_i + 1, header->prog_name, close_i, str);
		cw_cat_comment(name + open_i + 1, header->comment, close_i, str);
	}
}
