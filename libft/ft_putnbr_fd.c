/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 07:27:00 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/17 07:31:30 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		max;

	max = 1;
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	while (n / max >= 10)
		max *= 10;
	while (max)
	{
		ft_putchar_fd(n / max + '0', fd);
		n = n - ((n / max) * max);
		max = max / 10;
	}
}
