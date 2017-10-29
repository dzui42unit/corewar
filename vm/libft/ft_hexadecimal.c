/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:57:21 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 18:57:31 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_no_minus_base_16(t_flags *fl, int base, int nb_case)
{
	char *number;
	char ch;

	ft_set_counters_def(fl);
	ft_set_char(fl, &ch);
	if (fl->hash)
		fl->hash = 2;
	number = ft_itoa_base_unsigned(fl, base, nb_case);
	if (fl->prec == -1 && ft_strequ(number, "0"))
		ft_inv_prec_null_16(fl, ' ');
	else
	{
		ft_count_width_prec_16(fl, number, &ch);
		if (fl->hash && fl->zero && fl->prec == 0)
			ft_no_minus_16_hash(fl, number, ch, nb_case);
		else
			ft_no_minus_16_no_hash(fl, number, ch, nb_case);
	}
	free(number);
}

void	ft_no_minus_16_hash(t_flags *fl, char *nb, char ch, int nb_case)
{
	fl->counter += 2;
	if (nb_case)
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
	while (fl->k_count > 0)
	{
		fl->counter++;
		write(1, &ch, 1);
		fl->k_count--;
	}
	while (fl->j_count > 0)
	{
		fl->counter++;
		write(1, "0", 1);
		fl->j_count--;
	}
	while (nb[fl->i_count])
	{
		fl->counter++;
		write(1, &nb[fl->i_count++], 1);
	}
}

void	ft_no_minus_16_no_hash(t_flags *fl, char *number, char ch, int nb_case)
{
	while (fl->k_count > 0)
	{
		fl->counter++;
		write(1, &ch, 1);
		fl->k_count--;
	}
	if ((fl->hash && (!ft_strequ(number, "0"))) || fl->conver == 'p')
	{
		fl->counter += 2;
		if (nb_case)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
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

void	ft_minus_base_16(t_flags *fl, int base, int nb_case)
{
	char	*number;

	ft_set_counters_def(fl);
	number = ft_itoa_base_unsigned(fl, base, nb_case);
	if (fl->hash)
		fl->hash = 2;
	if (fl->prec == -1 && ft_strequ(number, "0"))
		ft_inv_prec_null_16(fl, ' ');
	else
	{
		fl->j_count = (int)(fl->prec - ft_strlen(number) - fl->hash);
		if (fl->j_count >= 0)
		{
			fl->k_count = (int)(fl->width - fl->j_count - ft_strlen(number));
			fl->k_count -= fl->hash;
		}
		else
			fl->k_count = (int)(fl->width - ft_strlen(number) - fl->hash);
		ft_minus_base_16_print(fl, number, nb_case);
	}
	free(number);
}

void	ft_minus_base_16_print(t_flags *fl, char *number, int nb_case)
{
	while (fl->j_count > 0)
	{
		fl->counter++;
		write(1, "0", 1);
		fl->j_count--;
	}
	if ((fl->hash && (!ft_strequ(number, "0"))) || fl->conver == 'p')
	{
		fl->counter += 2;
		if (nb_case)
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
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
