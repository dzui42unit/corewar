/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:25:11 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 17:25:13 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_itoa_base_unsigned(t_flags *fl, int base, int nb_case)
{
	char		*res;
	int			nb;
	uintmax_t	number;

	nb = 0;
	res = NULL;
	if (fl->u_big)
		number = (unsigned long)va_arg(fl->arg_ptr, unsigned long);
	else
		number = ft_type_unsigned(fl);
	if (number == 0)
		res = ft_make_zero();
	else
	{
		nb = ft_count_digs_unsigned(number, nb, base);
		res = (char *)malloc(sizeof(char) * (nb + 1));
		res[nb--] = '\0';
		while (number > 0)
		{
			res[nb--] = fl->numbers[number % base];
			number /= base;
		}
	}
	ft_make_number(res, nb_case);
	return (res);
}

char	*ft_make_zero(void)
{
	char *res;

	res = (char *)malloc(sizeof(char) + 1);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

void	ft_make_number(char *res, int nb_case)
{
	int i;

	i = 0;
	while (res[i])
	{
		if (nb_case)
			res[i] = (char)ft_toupper(res[i]);
		i++;
	}
}

char	*ft_itoa_base_signed(t_flags *fl, int base, int nb_case)
{
	char		*res;
	int			nb;
	intmax_t	number;
	int			flag;

	nb = 0;
	res = NULL;
	flag = 0;
	number = ft_type_signed(fl);
	if (number == 0)
		res = ft_make_zero();
	else
	{
		nb = ft_count_digs_signed(number, nb, base);
		res = (char *)malloc(sizeof(char) * (nb + 1));
		ft_set_minus(res, flag, number, &nb);
		while (number != 0)
		{
			res[nb--] = fl->numbers[ft_get_index(number, base)];
			number /= base;
		}
	}
	ft_make_number(res, nb_case);
	return (res);
}
