/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:09:04 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 18:09:06 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(char *str, t_flags *fl)
{
	if (ft_strchr("s", str[fl->i]) || ft_strchr("S", str[fl->i]))
		ft_string(fl);
	if (ft_strchr("c", str[fl->i]) || ft_strchr("C", str[fl->i]))
		ft_char(fl);
	if (ft_strchr("x", str[fl->i]) || ft_strchr("X", str[fl->i]))
		ft_numbers_base(fl, str[fl->i]);
	if (ft_strchr("o", str[fl->i]))
		ft_numbers_base(fl, str[fl->i]);
	if (ft_strchr("O", str[fl->i]))
	{
		fl->conver = 'O';
		ft_numbers_base(fl, str[fl->i]);
	}
	if (ft_strchr("p", str[fl->i]))
	{
		fl->conver = 'p';
		ft_numbers_base(fl, str[fl->i]);
	}
	if (ft_strchr("n", str[fl->i]))
		ft_n(fl);
	ft_decimal_conver(fl, str);
}

void	ft_decimal_conver(t_flags *fl, char *str)
{
	if (ft_strchr("d", str[fl->i]) || ft_strchr("i", str[fl->i]))
	{
		ft_numbers_base(fl, str[fl->i]);
	}
	if (ft_strchr("u", str[fl->i]))
	{
		fl->u = 1;
		ft_numbers_base(fl, str[fl->i]);
	}
	if (ft_strchr("U", str[fl->i]))
	{
		fl->u_big = 1;
		ft_numbers_base(fl, str[fl->i]);
	}
	if (ft_strchr("D", str[fl->i]))
	{
		fl->conver = 'D';
		ft_numbers_base(fl, str[fl->i]);
	}
}

void	ft_start_conversion(int flag, t_flags *fl, char *str)
{
	if (flag)
	{
		ft_conversion(str, fl);
		fl->i++;
	}
	if (fl->perc == '%')
	{
		ft_char(fl);
		fl->i++;
	}
}

void	ft_ival_prec_8(t_flags *fl, char ch)
{
	fl->j_count = fl->width;
	while (fl->j_count > 0)
	{
		fl->counter++;
		write(1, &ch, 1);
		fl->j_count--;
	}
	if (fl->hash)
	{
		fl->counter++;
		write(1, "0", 1);
	}
}
