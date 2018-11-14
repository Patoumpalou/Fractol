/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:44:42 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/22 08:25:57 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int a;

	if (needle[0] == '\0' || needle == haystack)
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && len)
	{
		a = 0;
		if (haystack[i] == needle[a])
		{
			while (haystack[i] && haystack[i] == needle[a] && len--)
			{
				a++;
				i++;
			}
			if (needle[a] == '\0')
				return ((char*)&haystack[i - a]);
			i = (i - a) + 1;
			len = len + a - 1;
		}
		i++;
		len--;
	}
	return (NULL);
}
