/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:58:53 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 17:58:55 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_flags(char *str, t_flags *fl)
{
	int flag;
	int prev;

	flag = 0;
	if (ft_percent(fl, str))
		return ;
	prev = -1;
	while (ft_strchr(fl->string, str[fl->i]) && str[fl->i])
	{
		if (prev == fl->i)
			fl->i++;
		prev = fl->i;
		if (str[fl->i] == '%')
		{
			fl->perc = '%';
			break ;
		}
		if (ft_strchr(fl->conversion, str[fl->i]) && str[fl->i])
		{
			flag = 1;
			break ;
		}
		ft_flags_1(fl, str);
	}
	ft_start_conversion(flag, fl, str);
}

void	ft_width(char *str, t_flags *fl)
{
	int i;
	int	pow;

	i = 0;
	pow = 1;
	while (ft_isdigit(str[fl->i]))
	{
		i++;
		pow *= 10;
		fl->i++;
	}
	pow /= 10;
	fl->width = 0;
	while (i > 0)
	{
		fl->width += (str[fl->i - i--] - '0') * pow;
		pow /= 10;
	}
}
