/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 20:31:45 by pihouvie          #+#    #+#             */
/*   Updated: 2017/09/19 22:19:40 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[0] == '-' || str[0] == '+')
		i--;
	return (i);
}

char	*final(int value, char *base_to, char *nbr)
{
	char			*tab;
	int				count;
	int				i;
	long int		value2;

	i = 1;
	value2 = 1;
	count = 0;
	while ((value / value2) >= ft_strlen(base_to))
		value2 = value2 * ft_strlen(base_to);
	tab = (char*)malloc(sizeof(char) * count);
	if (nbr[0] == '-')
	{
		tab[0] = '-';
		count++;
	}
	while (value2 != 0)
	{
		tab[count] = base_to[value / value2];
		value = value - ((value / value2) * value2);
		value2 = value2 / ft_strlen(base_to);
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

int		check(char *bf, char *bt, int i)
{
	int j;

	i = 0;
	while (bf[i++])
	{
		j = 0;
		while (j < i)
		{
			if (bf[i] == bf[j] || bf[i] == '+' || bf[i] == '-')
				return (0);
			j++;
		}
	}
	i = 0;
	while (bt[i++])
	{
		j = 0;
		while (j < i)
		{
			if (bt[i] == bt[j] || bt[i] == '-' || bt[i] == '+')
				return (0);
			j++;
		}
	}
	return (1);
}

int		check2(char *nbr, char *base_from)
{
	int i;
	int j;

	i = 0;
	if (nbr[0] == '+' || nbr[0] == '-')
		i++;
	while (nbr[i])
	{
		j = 0;
		while (nbr[i] != base_from[j])
		{
			if (base_from[j] == '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			i;
	long int	value;
	long int	pos_max;
	long int	x;

	if ((check(base_from, base_to, 0) == 0) || (check2(nbr, base_from) == 0))
		return (NULL);
	pos_max = ft_strlen(base_from);
	i = 1;
	while (i++ < (ft_strlen(nbr) - 1))
		pos_max = pos_max * ft_strlen(base_from);
	i = 0;
	if (nbr[0] == '-' || nbr[0] == '+')
		i++;
	value = 0;
	while (i <= ft_strlen(nbr))
	{
		x = 0;
		while ((nbr[i] != base_from[x]) && base_from[x])
			x++;
		value = value + (x * (pos_max));
		pos_max = pos_max / ft_strlen(base_from);
		i++;
	}
	return (final(value, base_to, nbr));
}
