/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:41:54 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/15 21:15:03 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	i = 0;
	while (src[i])
		i++;
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
