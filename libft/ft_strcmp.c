/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:19:01 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/15 21:11:59 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	x;
	unsigned char	y;

	i = 0;
	x = s1[i];
	y = s2[i];
	while (x == y && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
		x = s1[i];
		y = s2[i];
	}
	return (x - y);
}
