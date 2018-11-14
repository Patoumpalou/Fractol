/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:02:19 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/15 21:02:39 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cs;
	int		i;

	i = 0;
	cs = (char*)s;
	while (n)
	{
		if ((unsigned char)cs[i] == (unsigned char)c)
			return (&cs[i]);
		n--;
		i++;
	}
	return (NULL);
}
