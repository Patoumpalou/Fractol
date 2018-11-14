/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 06:23:26 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/30 04:50:36 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
	{
		str[len1] = s1[len1];
		len1++;
	}
	while (s2[len2])
		str[len1++] = s2[len2++];
	str[len1] = '\0';
	return (str);
}
