/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_display_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:25:32 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 11:25:33 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** cw_display_hex_ : Write on the standard output an unsigned long long int
** according to the model of hex dump. The function takes in parameter a number
** and the number of octet(s) to print.
** e.g  cw_display_hex(42, 4); -> 0x00 0x00 0x00 0x2a
*/

static void		cw_print_char(char str[100], int i, int length)
{
	int		flag;
	int		count;

	flag = 0;
	count = 0;
	if (length % 2 != 0 && length != 5)
		flag = 1;
	while (str[i])
	{
		count++;
		ft_putchar(str[i]);
		i++;
		if (count % 2 - flag == 0 && str[i])
			ft_printf(" 0x");
	}
}

static void		cw_print_hex(char str[100], int octet_nbr)
{
	int		i;
	int		flag;
	int		length;

	length = ft_strlen(str);
	i = length - octet_nbr * 2;
	flag = 1;
	if (length % 2 != 0)
		flag = 0;
	while (i < 0)
	{
		ft_putchar('0');
		if (-i % 2 - flag == 0 && octet_nbr > 1)
		{
			if (i >= -1 && *str == '\0')
				;
			else
				ft_printf(" 0x");
		}
		i++;
	}
	cw_print_char(str, i, length);
}

static int		cw_count_symbol(unsigned long long int nbr, int base)
{
	int		out;

	out = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		out++;
	}
	return (out);
}

void			cw_display_hex(unsigned long long int nbr, int octet_nbr)
{
	int		length;
	char	str[100];

	ft_bzero(str, 100);
	length = cw_count_symbol(nbr, 16);
	length--;
	ft_printf("0x");
	while (nbr != 0)
	{
		if (nbr % 16 <= 9)
			str[length--] = (nbr % 16) + '0';
		else
			str[length--] = (nbr % 16) + 'a' - 10;
		nbr /= 16;
	}
	cw_print_hex(str, octet_nbr);
}
