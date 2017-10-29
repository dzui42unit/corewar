/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:03:50 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 19:03:57 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_n(t_flags *fl)
{
	unsigned int *i;

	i = va_arg(fl->arg_ptr, unsigned int *);
	*i = (unsigned int)fl->counter;
}

int		ft_star(t_flags *fl)
{
	int number;

	number = va_arg(fl->arg_ptr, int);
	return (number);
}
