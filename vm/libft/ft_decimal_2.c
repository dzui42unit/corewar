/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:56:11 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 18:56:21 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_no_min_10(t_flags *fl, char *number, char ch)
{
	ft_count_width_prec_10_no_minus(fl, number);
	if (fl->zero)
	{
		if (fl->prec == -1 || fl->prec > 0)
			ch = ' ';
		ft_no_minus_zero_10(fl, number, ch);
	}
	else
		ft_no_minus_no_zero_10(fl, number);
	while (number[fl->i_count])
	{
		write(1, &number[fl->i_count++], 1);
		fl->counter++;
	}
}

void	ft_set_counters_def(t_flags *fl)
{
	fl->i_count = 0;
	fl->j_count = 0;
	fl->k_count = 0;
}

void	ft_no_minus_zero_10(t_flags *fl, char *number, char ch)
{
	if (fl->space && number[0] != '-' && !(fl->u || fl->u_big))
	{
		fl->counter++;
		write(1, " ", 1);
		fl->k_count -= fl->space;
	}
	if (fl->plus && number[0] != '-' && !(fl->u || fl->u_big))
	{
		fl->counter++;
		write(1, "+", 1);
	}
	if (number[fl->i_count] == '-')
	{
		fl->counter++;
		write(1, &number[fl->i_count++], 1);
	}
	ft_no_minus_zero_10_2(fl, ch);
}

void	ft_no_minus_zero_10_2(t_flags *fl, char ch)
{
	while (fl->k_count > 0)
	{
		fl->k_count--;
		write(1, &ch, 1);
		fl->counter++;
	}
	while (fl->j_count > 0)
	{
		fl->j_count--;
		write(1, "0", 1);
		fl->counter++;
	}
}

void	ft_no_minus_no_zero_10(t_flags *fl, char *number)
{
	while (fl->k_count > 0)
	{
		fl->k_count--;
		write(1, " ", 1);
		fl->counter++;
	}
	if (fl->plus && number[0] != '-' && !(fl->u || fl->u_big))
	{
		fl->counter++;
		write(1, "+", 1);
	}
	if (number[fl->i_count] == '-')
	{
		fl->counter++;
		write(1, &number[fl->i_count++], 1);
	}
	while (fl->j_count > 0)
	{
		fl->j_count--;
		write(1, "0", 1);
		fl->counter++;
	}
}
