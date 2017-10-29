/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:59:11 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 18:59:20 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_count_width_prec_10_no_minus(t_flags *fl, char *number)
{
	fl->j_count = (int)(fl->prec - ft_strlen(number));
	if (number[0] == '-')
		fl->j_count++;
	if (fl->j_count >= 0)
		fl->k_count = (int)(fl->width - fl->j_count - ft_strlen(number));
	else
		fl->k_count = (int)(fl->width - ft_strlen(number));
	if (number[0] != '-' && fl->plus && !(fl->u || fl->u_big))
		fl->k_count--;
	if (number[0] != '-' && !fl->plus && fl->space && fl->k_count < 0
		&& !(fl->u || fl->u_big))
		fl->k_count = 1;
}

void	ft_count_width_prec_10_minus(t_flags *fl, char *number)
{
	fl->j_count = (int)(fl->prec - ft_strlen(number));
	if (number[0] == '-')
		fl->j_count++;
	if (fl->j_count >= 0)
		fl->k_count = (int)(fl->width - fl->j_count - ft_strlen(number));
	else
		fl->k_count = (int)(fl->width - ft_strlen(number));
	if (number[0] != '-' && fl->plus && !(fl->u || fl->u_big))
		fl->k_count--;
	if (number[0] != '-' && !fl->plus && fl->space && fl->k_count < 0)
		fl->k_count = 1;
}

void	ft_count_width_prec_16(t_flags *fl, char *number, char *ch)
{
	fl->j_count = (int)(fl->prec - ft_strlen(number));
	if (fl->j_count >= 0)
	{
		*ch = ' ';
		fl->k_count = (int)(fl->width - fl->j_count - ft_strlen(number));
		fl->k_count -= fl->hash;
	}
	else
		fl->k_count = (int)(fl->width - ft_strlen(number) - fl->hash);
}

void	ft_inv_prec_null_16(t_flags *fl, char ch)
{
	fl->j_count = fl->width;
	if (fl->conver == 'p')
		fl->j_count -= 2;
	while (fl->j_count > 0)
	{
		fl->counter++;
		write(1, &ch, 1);
		fl->j_count--;
	}
	if (fl->conver == 'p')
	{
		fl->counter += 2;
		write(1, "0x", 2);
	}
}

void	ft_inv_prec_null_10(t_flags *fl, char ch)
{
	fl->j_count = fl->width;
	ch = ' ';
	while (fl->j_count > 0)
	{
		fl->counter++;
		write(1, &ch, 1);
		fl->j_count--;
	}
}
