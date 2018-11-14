/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:10:42 by pihouvie          #+#    #+#             */
/*   Updated: 2018/01/10 22:18:16 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_checkline(char *buff, char **bite, int ret)
{
	int		i;
	int		x;

	x = ret;
	i = 0;
	while (buff[i] && buff[i] != '\n' && ret > 0)
	{
		ret--;
		i++;
	}
	if (buff[i] && buff[i] == '\n')
	{
		*bite = ft_strsub(buff, i + 1, BUFF_SIZE);
		buff[i] = '\0';
		return (i + 1);
	}
	if (x < BUFF_SIZE)
		return (-1);
	return (0);
}

int		ifbuff(char **line, char *buff, char *bite)
{
	int		couille;

	couille = 0;
	if (buff[0])
	{
		if ((couille = ft_checkline(buff, &bite, BUFF_SIZE)) > 0)
		{
			*line = ft_strndup(buff, couille);
			ft_strcpy(buff, bite);
			free(bite);
			return (1);
		}
		else
		{
			*line = ft_strdup(buff);
			ft_bzero(buff, BUFF_SIZE);
		}
	}
	else
		*line = ft_memalloc(1);
	return (0);
}

int		whatdowedo(int ret, int couille, char **line, char *buff)
{
	if (ret == 0 && couille == 0 && *line[0] != '\0')
		couille = -1;
	if (ret == -1)
		return (-1);
	if (couille == -1)
	{
		ft_bzero(buff, BUFF_SIZE);
		return (1);
	}
	if (ret == 0 && buff[0] == '\0' && *line[0] == '\0')
	{
		ft_bzero(buff, BUFF_SIZE);
		return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		buff[12288][BUFF_SIZE + 1];
	int				ret;
	char			*tmp;
	int				couille;
	char			*bite;

	bite = NULL;
	ret = 0;
	if (fd < 0 || fd > 12287 || !line)
		return (-1);
	if ((couille = ifbuff(line, buff[fd], NULL)) == 1)
		return (1);
	while (couille == 0 && ((ret = read(fd, buff[fd], BUFF_SIZE)) > 0))
	{
		buff[fd][ret] = '\0';
		couille = ft_checkline(buff[fd], &bite, ret);
		tmp = ft_strjoin(*line, buff[fd]);
		free(*line);
		*line = tmp;
		if (couille > 0)
			ft_strcpy(buff[fd], bite);
	}
	if (bite != NULL)
		free(bite);
	return (whatdowedo(ret, couille, line, buff[fd]));
}
