/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 01:00:41 by pihouvie          #+#    #+#             */
/*   Updated: 2017/11/18 04:31:03 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static char	**countword(const char *s, char c)
{
	int		i;
	int		count;
	char	**tab;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && c == s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] && c != s[i])
			i++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * count + 1)))
		return (NULL);
	tab[count] = 0;
	return (tab);
}

static char	**countchar(const char *str, char c, char **tab)
{
	int i;
	int k;
	int count;

	count = 0;
	k = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && c != str[i])
		{
			count++;
			i++;
		}
		if (count != 0)
		{
			if (!(tab[k++] = (char*)malloc(sizeof(char) * count + 1)))
				return (NULL);
			count = 0;
		}
	}
	return (tab);
}

static char	**fill(const char *str, char c, char **tab)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			tab[k][j] = str[i];
			i++;
			j++;
		}
		if (j != 0)
			tab[k][j] = '\0';
		k++;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = countword(s, c);
	if (tab == NULL)
		return (NULL);
	tab = countchar(s, c, tab);
	if (tab == NULL)
		return (NULL);
	return (fill(s, c, tab));
}
