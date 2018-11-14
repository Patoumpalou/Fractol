/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:40:26 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/18 04:21:41 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		itoa_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoa(int n)
{
	char	*result;
	int		count;
	int		a;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = 2;
	neg = 0;
	itoa_neg(&n, &neg);
	a = n;
	while (a /= 10)
		count++;
	count = count + neg;
	if (!(result = (char*)malloc(sizeof(char) * count)))
		return (NULL);
	result[--count] = '\0';
	while (count-- >= 0)
	{
		result[count] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		result[0] = '-';
	return (result);
}
