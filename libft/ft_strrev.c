/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:54:31 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/20 10:45:20 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		count;
	int		i;

	if (s == NULL)
		return (NULL);
	i = (int)ft_strlen(s) - 1;
	count = 0;
	while (count <= i)
		ft_swap(&s[count++], &s[i--]);
	return (s);
}
