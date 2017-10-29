/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_additional_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:34:05 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 13:26:08 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			cw_isprint_without_space(int c)
{
	return ((c >= 33 && c <= 126) ? 1 : 0);
}

int			cw_nbr_of_letter_in_str(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

/*
** cw_strcomment_trim : Do the same as the ft_strtrim + trim the comment after
** comment_char
*/

static void	trim_comment(char const *line, size_t i, size_t *length,
							char comment_char)
{
	size_t	index;
	char	inside;

	index = i;
	inside = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '\"')
			inside ^= 1;
		if (line[index] == comment_char && inside == 0)
		{
			*length = index;
			break ;
		}
		index++;
	}
}

static void	trim_spaces(char const *line, size_t *i, char comment_ch, char flag)
{
	if (flag == 1)
	{
		while (line[(*i) - 1] == ' ' || line[(*i) - 1] == '\n' ||
							line[(*i) - 1] == '\t')
		{
			if (line[(*i) - 1] == comment_ch)
				break ;
			(*i)--;
		}
	}
	else
	{
		while (line[*i] == ' ' || line[*i] == '\n' || line[*i] == '\t')
		{
			if (line[*i] == comment_ch)
				break ;
			(*i)++;
		}
	}
}

char		*cw_strcomment_trim(char *line, char comment_char)
{
	char	*new_line;
	int		new_lenght;
	size_t	length;
	size_t	i;

	if (!line)
		return (NULL);
	i = 0;
	length = ft_strlen(line);
	trim_spaces(line, &i, comment_char, 0);
	trim_spaces(line, &length, comment_char, 1);
	trim_comment(line, i, &length, comment_char);
	new_lenght = length - i;
	if (new_lenght <= 0)
		new_lenght = 0;
	else
		(void)new_lenght;
	if (!(new_line = ft_strsub(line, i, new_lenght)))
		return (NULL);
	return (new_line);
}
