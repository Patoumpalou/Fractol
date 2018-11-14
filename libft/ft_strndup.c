/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 06:52:30 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/18 06:58:26 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *src, size_t len)
{
	int		i;
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (src[i] && len)
	{
		str[i] = src[i];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
