/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:28:36 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/22 08:58:55 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int a;

	if (needle[0] == '\0' || haystack == needle)
		return ((char*)haystack);
	i = 0;
	while (haystack[i])
	{
		a = 0;
		if (haystack[i] == needle[a])
		{
			while (haystack[i] && needle[a] && haystack[i] == needle[a])
			{
				i++;
				a++;
			}
			if (needle[a] == '\0')
				return ((char*)&haystack[i - a]);
			i = (i - a) + 1;
		}
		i++;
	}
	return (NULL);
}
