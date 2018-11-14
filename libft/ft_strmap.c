/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 04:51:18 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/17 06:46:51 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*coucou;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(coucou = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		coucou[i] = f(s[i]);
		i++;
	}
	coucou[i] = '\0';
	return (coucou);
}
