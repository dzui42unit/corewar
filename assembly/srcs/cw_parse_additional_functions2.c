/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_additional_functions2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:41:00 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:42:21 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t			cw_intlen(int nbr)
{
	size_t length;

	length = 0;
	if (nbr <= 0)
		length++;
	while (nbr)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

long long int	cw_lltoi(const char *nptr)
{
	int				i;
	long long int	result;
	int				neg;

	i = 0;
	result = 0;
	neg = 0;
	while ((nptr[i] == '\n') || (nptr[i] == '\t') || (nptr[i] == '\v') ||
			(nptr[i] == ' ') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	if (neg == 1)
		result = -result;
	if (*nptr == '-' && (result > 0 || ft_strlen(nptr) > 20))
		return (0);
	else if (*nptr != '-' && (result < 0 || ft_strlen(nptr) > 19))
		return (-1);
	return (result);
}

void			cw_strtab_free(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

/*
** cw_isnumber_syntax : Check the syntax of a string, if the string has the
** number syntax (all caracter digit) return 1 else return 0.
** If the flag sign is at 1, the number is signed, else the number is unsigned.
*/

static int		cw_str_condition_fulfilling(const char *str, int (*type)())
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((*type)(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int				cw_isnumber_syntax(char *str, char sign)
{
	if (*str == '-' && sign == 1)
	{
		if (cw_str_condition_fulfilling(str + 1, ft_isdigit) == 0)
			return (-1);
	}
	else
	{
		if (cw_str_condition_fulfilling(str, ft_isdigit) == 0)
			return (-1);
	}
	return (1);
}
