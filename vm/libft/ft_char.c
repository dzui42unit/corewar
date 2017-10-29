/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:17:00 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 16:17:15 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_flags *fl)
{
	char ch;

	if (fl->perc == ' ')
		ch = (char)va_arg(fl->arg_ptr, int);
	else
		ch = fl->perc;
	if (!fl->minus)
		ft_char_no_minus(ch, fl);
	else
		ft_char_minus(ch, fl);
}

void	ft_char_no_minus(char ch, t_flags *fl)
{
	int		i;
	char	field;

	if (fl->zero)
		field = '0';
	else
		field = ' ';
	i = 0;
	while (i < fl->width - 1)
	{
		write(1, &field, 1);
		fl->counter++;
		i++;
	}
	write(1, &ch, 1);
	fl->counter++;
}

void	ft_char_minus(char ch, t_flags *fl)
{
	int		i;

	i = 0;
	write(1, &ch, 1);
	fl->counter++;
	while (i < fl->width - 1)
	{
		write(1, " ", 1);
		fl->counter++;
		i++;
	}
}
