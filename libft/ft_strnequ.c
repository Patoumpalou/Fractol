/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:51:22 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/22 10:40:06 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && n)
	{
		ft_tolower(s1[i]);
		ft_tolower(s2[i]);
		if (s1[i] != s2[i])
			return (0);
		i++;
		n--;
	}
	return (1);
}
