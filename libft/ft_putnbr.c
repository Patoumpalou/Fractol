/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:00:18 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/18 04:24:24 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	int max;

	max = 1;
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar('-');
		ft_putchar('2');
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	while (n / max >= 10)
		max = max * 10;
	while (max != 0)
	{
		ft_putchar(n / max + '0');
		n = n - ((n / max) * max);
		max = max / 10;
	}
}
