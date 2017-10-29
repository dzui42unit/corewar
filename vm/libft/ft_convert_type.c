/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:06:05 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 19:06:13 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_type_signed(t_flags *fl)
{
	if (fl->conver == 'D')
		return ((long)va_arg(fl->arg_ptr, long));
	else
	{
		if (fl->z)
			return ((size_t)va_arg(fl->arg_ptr, size_t));
		else if (fl->j)
			return ((intmax_t)va_arg(fl->arg_ptr, intmax_t));
		else if (fl->ll)
			return ((long long)va_arg(fl->arg_ptr, long long));
		else if (fl->l)
			return ((long)va_arg(fl->arg_ptr, long));
		else if (fl->h)
			return ((short)va_arg(fl->arg_ptr, int));
		else if (fl->hh)
			return ((char)va_arg(fl->arg_ptr, int));
		else
			return ((int)va_arg(fl->arg_ptr, int));
	}
}

uintmax_t	ft_type_unsigned(t_flags *fl)
{
	if (fl->conver == 'O' || fl->conver == 'p')
		return ((unsigned long)va_arg(fl->arg_ptr, unsigned long));
	else
	{
		if (fl->z)
			return ((size_t)va_arg(fl->arg_ptr, size_t));
		else if (fl->j)
			return ((uintmax_t)va_arg(fl->arg_ptr, uintmax_t));
		else if (fl->ll)
			return ((unsigned long long)
					va_arg(fl->arg_ptr, unsigned long long));
		else if (fl->l)
			return ((unsigned long)va_arg(fl->arg_ptr, unsigned long));
		else if (fl->h)
			return ((unsigned short)va_arg(fl->arg_ptr, unsigned int));
		else if (fl->hh)
			return ((unsigned char)va_arg(fl->arg_ptr, unsigned int));
		else
			return ((unsigned int)va_arg(fl->arg_ptr, unsigned int));
	}
}

void		ft_no_minus_base_10(t_flags *fl, int base, int nb_case)
{
	char	*number;
	char	ch;

	ft_set_counters_def(fl);
	ch = ' ';
	if (fl->u || fl->u_big)
		number = ft_itoa_base_unsigned(fl, base, nb_case);
	else
		number = ft_itoa_base_signed(fl, base, nb_case);
	if (fl->zero)
		ch = '0';
	if (fl->prec == -1 && ft_strequ(number, "0"))
		ft_inv_prec_null_10(fl, ch);
	else
		ft_print_no_min_10(fl, number, ch);
	free(number);
}
