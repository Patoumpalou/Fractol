/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:39:10 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/15 21:03:32 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	cs1;
	unsigned char	cs2;
	int				i;

	i = 0;
	while (n)
	{
		cs1 = ((unsigned char*)s1)[i];
		cs2 = ((unsigned char*)s2)[i];
		if (cs1 != cs2)
			return (cs1 - cs2);
		i++;
		n--;
	}
	return (0);
}
