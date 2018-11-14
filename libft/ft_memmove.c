/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 02:53:57 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/15 21:06:27 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	s = (char*)src;
	d = (char*)dst;
	if (s > d)
		ft_memcpy(d, s, len);
	else
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	return (dst);
}
