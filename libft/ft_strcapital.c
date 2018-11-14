/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapital.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 07:12:41 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/18 07:12:54 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapital(char *str)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[0] && str[0] <= 'z')
		{
			str[0] = str[0] - 32;
			i++;
		}
		if (('0' > str[i - 1] || ('9' < str[i - 1] && str[i - 1] < 'A') ||
					('Z' < str[i - 1] && str[i - 1] < 'a') || str[i - 1] >
					'z') && ('a' <= str[i] && str[i] <= 'z'))
			str[i] = str[i] - 32;
		if ((('0' <= str[i - 1] && str[i - 1] <= '9') || ('A' <= str[i - 1]
						&& str[i - 1] <= 'Z') || ('a' <= str[i - 1] && str[i
							- 1] <= 'z')) && ('A' <= str[i] && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
