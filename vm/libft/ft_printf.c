/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:04:12 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 18:31:26 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	t_flags flags;

	flags.i = 0;
	flags.counter = 0;
	flags.inv_conv = 0;
	flags.string = "%sScCxXdDoOiuUp-+0123456789#n.* hljz";
	flags.conversion = "sScCxXdDoOiuUpn";
	flags.numbers = "0123456789abcdef";
	va_start(flags.arg_ptr, str);
	struct_def(&flags);
	while (str[flags.i])
	{
		simple_string(&flags, str);
		struct_def(&flags);
		if (str[flags.i] == '%')
			flags.i++;
		find_flags(str, &flags);
	}
	va_end(flags.arg_ptr);
	return (flags.counter);
}

void	simple_string(t_flags *fl, char *str)
{
	if (fl->inv_conv)
	{
		if (fl->minus)
			ft_char_minus(str[fl->i], fl);
		else
			ft_char_no_minus(str[fl->i], fl);
		fl->i++;
	}
	while (str[fl->i] != '%' && str[fl->i])
	{
		fl->counter++;
		write(1, &str[fl->i++], 1);
	}
}

void	struct_def(t_flags *fl)
{
	fl->minus = 0;
	fl->plus = 0;
	fl->zero = 0;
	fl->hash = 0;
	fl->space = 0;
	fl->width = -1;
	fl->prec = 0;
	fl->perc = ' ';
	fl->hh = 0;
	fl->h = 0;
	fl->l = 0;
	fl->ll = 0;
	fl->j = 0;
	fl->z = 0;
	fl->u = 0;
	fl->u_big = 0;
	fl->inv_conv = 0;
	fl->conver = ' ';
	fl->i_count = 0;
	fl->j_count = 0;
	fl->k_count = 0;
}

void	ft_precision(char *str, t_flags *fl)
{
	int i;
	int	pow;

	i = 0;
	pow = 1;
	fl->i++;
	if ((str[fl->i] == '0') || (!ft_isdigit(str[fl->i]) && str[fl->i]))
	{
		fl->prec = -1;
		return ;
	}
	while (ft_isdigit(str[fl->i]))
	{
		i++;
		pow *= 10;
		fl->i++;
	}
	pow /= 10;
	fl->prec = 0;
	while (i > 0)
	{
		fl->prec += (str[fl->i - i--] - '0') * pow;
		pow /= 10;
	}
}

int		ft_percent(t_flags *fl, char *str)
{
	if (str[fl->i] == '%')
	{
		write(1, "%", 1);
		fl->counter++;
		fl->i++;
		return (1);
	}
	return (0);
}
