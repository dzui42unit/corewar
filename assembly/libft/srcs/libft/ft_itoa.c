/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:36:20 by ozabara           #+#    #+#             */
/*   Updated: 2016/12/03 15:03:37 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoaisneg(int *n, int *is_neg, int *len)
{
	if (*n < 0)
	{
		*n = *n * (-1);
		*is_neg = 1;
		*len = *len + 1;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		temp;
	int		is_neg;

	if (n == -2147483647 - 1)
		return (ft_strdup("-2147483648"));
	temp = n;
	is_neg = 0;
	len = 1;
	while (temp /= 10)
		len++;
	ft_itoaisneg(&n, &is_neg, &len);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (is_neg)
		*str = '-';
	return (str);
}
