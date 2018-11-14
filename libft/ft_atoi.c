/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:56:45 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/15 20:59:08 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		neg;

	neg = 0;
	nbr = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (48 <= str[i] && str[i] <= 57)
	{
		nbr = nbr * 10;
		nbr = nbr + ((int)str[i] - '0');
		i++;
	}
	if (neg == 1)
		nbr = -nbr;
	return (nbr);
}
