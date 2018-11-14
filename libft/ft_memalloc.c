/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 04:12:28 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/30 05:18:35 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*coucou;

	if (size > 4294967295)
		return (NULL);
	if (!(coucou = malloc(sizeof(void *) * size)))
		return (NULL);
	ft_memset(coucou, 0, size);
	return (coucou);
}
