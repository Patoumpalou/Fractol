/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 05:08:45 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/22 09:56:43 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	x;
	unsigned char	y;

	i = 0;
	x = (unsigned char)s1[i];
	y = (unsigned char)s2[i];
	if (n == 0)
		return (0);
	while (x == y && n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		x = s1[i];
		y = s2[i];
		i++;
		n--;
	}
	return (x - y);
}
