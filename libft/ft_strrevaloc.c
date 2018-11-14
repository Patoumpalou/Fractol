/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:54:31 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/20 10:27:58 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrevaloc(char *s)
{
	int		count;
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	i = (int)ft_strlen(s) - 1;
	count = 0;
	while (count <= i)
		ft_swap(&str[count++], &str[i--]);
	return (str);
}
