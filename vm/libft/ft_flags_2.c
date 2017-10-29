/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:02:22 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 19:02:31 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_1(t_flags *fl, char *str)
{
	if (str[fl->i] == '-')
	{
		fl->minus = 1;
		fl->i++;
	}
	if (str[fl->i] == '+')
	{
		fl->plus = 1;
		fl->i++;
	}
	if (str[fl->i] == '#')
	{
		fl->hash = 1;
		fl->i++;
	}
	ft_flags_2(fl, str);
}

void	ft_flags_2(t_flags *fl, char *str)
{
	if (str[fl->i] == ' ')
	{
		fl->space = 1;
		fl->i++;
	}
	if (str[fl->i] == '0' && str[fl->i - 1] != '.')
	{
		fl->zero = 1;
		fl->i++;
	}
	if (ft_isdigit(str[fl->i]) && str[fl->i] != '0')
	{
		ft_width(str, fl);
	}
	ft_flags_3(fl, str);
}

void	ft_flags_3(t_flags *fl, char *str)
{
	if (str[fl->i] == '*')
	{
		fl->width = ft_star(fl);
		fl->i++;
	}
	if (str[fl->i] == '.')
	{
		if (str[fl->i + 1] == '*')
		{
			fl->i++;
			fl->prec = ft_star(fl);
			fl->i++;
		}
		else
			ft_precision(str, fl);
	}
	ft_flags_4(fl, str);
}

void	ft_flags_4(t_flags *fl, char *str)
{
	if (str[fl->i] == 'h' && !fl->hh)
	{
		fl->h++;
		fl->i++;
	}
	if (fl->h == 2)
	{
		if (!ft_strchr(fl->string, str[fl->i]) && str[fl->i])
			fl->i++;
		fl->h = 0;
		fl->hh = 1;
	}
	ft_flags_5(fl, str);
}

void	ft_flags_5(t_flags *fl, char *str)
{
	if (str[fl->i] == 'l' && !fl->ll)
	{
		fl->i++;
		fl->l++;
	}
	if (fl->l == 2)
	{
		if (!ft_strchr(fl->string, str[fl->i]) && str[fl->i])
			fl->i++;
		fl->l = 0;
		fl->ll = 1;
	}
	if (str[fl->i] == 'j')
	{
		fl->i++;
		fl->j = 1;
	}
	if (str[fl->i] == 'z')
	{
		fl->i++;
		fl->z = 1;
	}
	if (!ft_strchr(fl->string, str[fl->i]) && str[fl->i])
		fl->inv_conv = 1;
}
