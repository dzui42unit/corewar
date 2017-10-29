/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:24:21 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 16:24:23 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_string(char *s, t_flags *fl)
{
	char	ch;

	fl->i_count = 0;
	fl->j_count = 0;
	ch = ' ';
	if (fl->prec != -1)
	{
		while (fl->i_count < fl->prec && s[fl->i_count])
		{
			write(1, &s[fl->i_count++], 1);
			fl->counter++;
		}
		if (fl->width > fl->prec)
			fl->j_count = fl->width - fl->prec;
		fl->i_count = 0;
		while (fl->i_count < fl->j_count)
		{
			write(1, &ch, 1);
			fl->i_count++;
			fl->counter++;
		}
	}
	else
		ft_print_width(fl, ch);
}

void	ft_no_minus_string(char *s, t_flags *fl)
{
	char ch;

	ft_set_vars(fl, &ch);
	if (fl->prec != -1)
	{
		if (fl->width > fl->prec)
			fl->j_count = fl->width - fl->prec;
		while (fl->i_count < fl->j_count)
		{
			write(1, &ch, 1);
			fl->counter++;
			fl->i_count++;
		}
		fl->i_count = 0;
		while (fl->i_count < fl->prec && s[fl->i_count])
		{
			write(1, &s[fl->i_count++], 1);
			fl->counter++;
		}
	}
	else
		ft_print_width(fl, ch);
}

void	ft_print_width(t_flags *fl, char ch)
{
	while (fl->i_count < fl->width)
	{
		fl->counter++;
		write(1, &ch, 1);
		fl->i_count++;
	}
}

void	ft_set_vars(t_flags *fl, char *ch)
{
	fl->i_count = 0;
	fl->j_count = 0;
	*ch = ' ';
	if (fl->zero)
		*ch = '0';
}

void	ft_string(t_flags *fl)
{
	char	*s;

	s = va_arg(fl->arg_ptr, char *);
	if (s == NULL)
		s = "(null)";
	if (fl->prec == -1 && fl->width == -1)
		return ;
	if (fl->prec == 0 || fl->prec > (int)ft_strlen(s))
		fl->prec = (int)ft_strlen(s);
	if (fl->minus)
		ft_minus_string(s, fl);
	else
		ft_no_minus_string(s, fl);
}
