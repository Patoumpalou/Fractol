/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:25:13 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/15 21:12:33 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	unsigned int	i2;

	i2 = 0;
	i = ft_strlen(s1);
	while (s2[i2] && i2 < len)
	{
		s1[i] = s2[i2];
		i2++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
