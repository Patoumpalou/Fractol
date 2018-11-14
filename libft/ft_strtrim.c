/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:29:39 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/20 10:23:01 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*nofrontspaces(char const *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return ((char*)&s[i]);
}

char		*ft_strtrim(char const *s)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	str = nofrontspaces(s);
	str = ft_strrevaloc(str);
	if (str == NULL)
		return (NULL);
	str = nofrontspaces(str);
	str = ft_strrevaloc(str);
	return (str);
}
