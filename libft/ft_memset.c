/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:21:32 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/15 21:07:38 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*dst;

	dst = b;
	i = 0;
	while (len)
	{
		dst[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
