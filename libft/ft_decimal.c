/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:54:06 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 18:54:20 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus_base_10(t_flags *fl, int base, int nb_case)
{
	char *number;
	char ch;

	ft_set_counters_def(fl);
	ft_set_char(fl, &ch);
	if (fl->u || fl->u_big)
		number = ft_itoa_base_unsigned(fl, base, nb_case);
	else
		number = ft_itoa_base_signed(fl, base, nb_case);
	if (fl->prec == -1 && ft_strequ(number, "0"))
		ft_inv_prec_null_10(fl, ch);
	else
	{
		ft_count_width_prec_10_minus(fl, number);
		if (fl->zero)
		{
			if (fl->k_count >= fl->j_count)
				ch = ' ';
			ft_minus_zero_10_1(fl, number, ch);
		}
		else
			ft_minus_no_zero_10_1(fl, number);
	}
	free(number);
}

void	ft_minus_zero_10_1(t_flags *fl, char *number, char ch)
{
	if (fl->space && !fl->plus && number[0] != '-' && !(fl->u || fl->u_big))
	{
		fl->k_count--;
		fl->counter++;
		write(1, " ", 1);
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
	ft_minus_zero_10_2(fl, number, ch);
}

void	ft_minus_zero_10_2(t_flags *fl, char *number, char ch)
{
	while (fl->j_count > 0)
	{
		fl->j_count--;
		write(1, "0", 1);
		fl->counter++;
	}
	while (number[fl->i_count])
	{
		write(1, &number[fl->i_count++], 1);
		fl->counter++;
	}
	while (fl->k_count > 0)
	{
		fl->k_count--;
		write(1, &ch, 1);
		fl->counter++;
	}
}

void	ft_minus_no_zero_10_1(t_flags *fl, char *number)
{
	if (fl->space && !fl->plus && number[0] != '-')
	{
		fl->k_count--;
		fl->counter++;
		write(1, " ", 1);
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
	ft_minus_no_zero_10_2(fl, number);
}

void	ft_minus_no_zero_10_2(t_flags *fl, char *number)
{
	while (fl->j_count > 0)
	{
		fl->j_count--;
		write(1, "0", 1);
		fl->counter++;
	}
	while (number[fl->i_count])
	{
		write(1, &number[fl->i_count++], 1);
		fl->counter++;
	}
	while (fl->k_count > 0)
	{
		fl->k_count--;
		write(1, " ", 1);
		fl->counter++;
	}
}
