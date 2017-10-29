/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:21:21 by dzui              #+#    #+#             */
/*   Updated: 2017/10/29 18:21:23 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

void			ft_error(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit(0);
}

unsigned int	ft_atoi_dec(char *nb)
{
	unsigned int	res;
	int				i;
	int				pow;

	i = 0;
	res = 0;
	pow = ft_pow(10, (int)(ft_strlen(nb) - 1));
	while (nb[i])
	{
		res += ((nb[i] - '0') * pow);
		pow /= 10;
		i++;
	}
	return (res);
}

int				ft_count_numbers(unsigned int number)
{
	int counter;

	counter = 0;
	while (number != 0)
	{
		counter++;
		number /= 16;
	}
	return (counter);
}

char			*ft_join(char *src, char *to_join)
{
	char	*res;
	char	*temp;
	int		sum;

	sum = (int)(3 + ft_strlen(src) + ft_strlen(to_join));
	temp = src;
	res = (char *)malloc(sum * sizeof(char));
	ft_strcpy(res, src);
	ft_strcat(res, to_join);
	free(temp);
	return (res);
}

int				ft_is_numberic_string(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
