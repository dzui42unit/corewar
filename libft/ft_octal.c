/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:51:44 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 18:51:56 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_minus_base_8(t_flags *fl, int base, int nb_case)
{
	char	*number;
	char	ch;

	fl->i_count = 0;
	fl->j_count = 0;
	fl->k_count = 0;
	ch = ' ';
	if (fl->zero && (fl->width > 0 && fl->prec <= 0))
		ch = '0';
	number = ft_itoa_base_unsigned(fl, base, nb_case);
	if (fl->prec == -1 && ft_strequ(number, "0"))
	{
		ch = ' ';
		ft_ival_prec_8(fl, ch);
	}
	else
	{
		ft_print_number_8(fl, number, ch);
		ft_no_minus_8_print(fl, number, ch);
	}
	free(number);
}

void	ft_print_number_8(t_flags *fl, char *number, char ch)
{
	fl->j_count = (int)(fl->prec - ft_strlen(number) - fl->hash);
	if (ft_strequ(number, "0") && fl->hash)
		fl->j_count += 1;
	if (fl->j_count >= 0)
	{
		ch = ' ';
		fl->k_count = (int)(fl->width - fl->j_count - ft_strlen(number));
		fl->k_count -= fl->hash;
	}
	else
		fl->k_count = (int)(fl->width - ft_strlen(number) - fl->hash);
}

void	ft_no_minus_8_print(t_flags *fl, char *number, char ch)
{
	while (fl->k_count > 0)
	{
		fl->counter++;
		write(1, &ch, 1);
		fl->k_count--;
	}
	if (fl->hash && !ft_strequ(number, "0"))
	{
		fl->counter++;
		write(1, "0", 1);
	}
	while (fl->j_count > 0)
	{
		fl->counter++;
		write(1, "0", 1);
		fl->j_count--;
	}
	while (number[fl->i_count])
	{
		fl->counter++;
		write(1, &number[fl->i_count++], 1);
	}
}

void	ft_minus_base_8(t_flags *fl, int base, int nb_case)
{
	char	*number;

	fl->i_count = 0;
	fl->j_count = 0;
	fl->k_count = 0;
	number = ft_itoa_base_unsigned(fl, base, nb_case);
	if (fl->prec == -1 && ft_strequ(number, "0"))
		ft_ival_prec_8(fl, ' ');
	else
	{
		fl->j_count = (int)(fl->prec - ft_strlen(number) - fl->hash);
		if (ft_strequ(number, "0") && fl->hash)
			fl->j_count += 1;
		if (fl->j_count >= 0)
		{
			fl->k_count = (int)(fl->width - fl->j_count - ft_strlen(number));
			fl->k_count -= fl->hash;
		}
		else
			fl->k_count = (int)(fl->width - ft_strlen(number) - fl->hash);
		ft_minus_8_print(fl, number);
	}
	free(number);
}

void	ft_minus_8_print(t_flags *fl, char *number)
{
	while (fl->j_count > 0)
	{
		fl->counter++;
		write(1, "0", 1);
		fl->j_count--;
	}
	if (fl->hash && !ft_strequ(number, "0"))
	{
		fl->counter++;
		write(1, "0", 1);
	}
	while (number[fl->i_count])
	{
		fl->counter++;
		write(1, &number[fl->i_count++], 1);
	}
	while (fl->k_count > 0)
	{
		fl->counter++;
		write(1, " ", 1);
		fl->k_count--;
	}
}
