/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:12:16 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:12:17 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

char			*ft_itoa_base(unsigned int nb)
{
	int		n;
	char	*str;
	char	*res;

	str = "0123456789abcdef";
	n = ft_count_numbers(nb);
	res = ft_strnew((size_t)n);
	n--;
	while (n >= 0)
	{
		res[n] = str[nb % 16];
		nb /= 16;
		n--;
	}
	return (res);
}

int				ft_find_number(char ch)
{
	char	*str;
	int		i;

	i = 0;
	ch = (char)ft_tolower(ch);
	str = "0123456789abcdef\0";
	while (str[i])
	{
		if (str[i] == ch)
			break ;
		i++;
	}
	return (i);
}

unsigned int	ft_convert_dec(char *prog_size_hex)
{
	int				i;
	int				pow;
	unsigned int	nb;

	pow = 0;
	nb = 0;
	i = (int)(ft_strlen(prog_size_hex) - 1);
	while (i >= 0)
	{
		nb += ft_find_number(prog_size_hex[i]) * ft_pow(16, pow);
		pow++;
		i--;
	}
	return (nb);
}

unsigned int	ft_convert_hex_to_dec(unsigned char *prog_size)
{
	int				i;
	char			*prog_size_hex;
	char			*temp;
	unsigned int	res;

	i = 0;
	prog_size_hex = ft_strnew(0);
	while (i < 4)
	{
		temp = ft_itoa_base(prog_size[i]);
		prog_size_hex = ft_join(prog_size_hex, temp);
		free(temp);
		i++;
	}
	res = ft_convert_dec(prog_size_hex);
	free(prog_size_hex);
	return (res);
}

unsigned int	ft_pow(unsigned int nb, int pow)
{
	unsigned int	res;
	int				i;

	i = 0;
	res = 1;
	while (i < pow)
	{
		res *= nb;
		i++;
	}
	return (res);
}
