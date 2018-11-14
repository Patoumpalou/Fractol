/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:07:00 by pihouvie          #+#    #+#             */
/*   Updated: 2018/02/01 17:08:53 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

int		key_hook(int keycode, t_ftl *e)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 49)
		fract_init(e);
	else if (keycode == 1 && e->stop == 0)
		e->stop = 1;
	else if (keycode == 1 && e->stop == 1)
		e->stop = 0;
	else if (keycode == 78)
		e->it_max += 5;
	else if (keycode == 69)
		e->it_max += 5;
	else if (keycode == 124)
		e->x1 -= 30 / e->zoom;
	else if (keycode == 123)
		e->x1 += 30 / e->zoom;
	else if (keycode == 126)
		e->y1 += 30 / e->zoom;
	else if (keycode == 125)
		e->y1 -= 30 / e->zoom;
	draw_reload(e);
	return (0);
}

int		mouse_hook(int mousecode, int x, int y, t_ftl *e)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, e);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(e);
	draw_reload(e);
	return (0);
}

void	ft_zoom(int x, int y, t_ftl *e)
{
	e->x2 = x;
	e->y2 = y;
	e->x1 = (x / e->zoom + e->x1) - ((e->zoom * 1.3) / 2);
	e->x1 += ((e->zoom * 1.3) / 2) - (x / (e->zoom * 1.3));
	e->y1 = (y / e->zoom + e->y1) - ((e->zoom * 1.3) / 2);
	e->y1 += ((e->zoom * 1.3) / 2) - (y / (e->zoom * 1.3));
	e->zoom *= 1.3;
	e->it_max += 5;
}

void	ft_dezoom(t_ftl *e)
{
	e->x1 = (e->x2 / e->zoom + e->x1) - ((e->zoom / 1.3) / 2);
	e->x1 += ((e->zoom / 1.3) / 2) - (e->x2 / (e->zoom / 1.3));
	e->y1 = (e->y2 / e->zoom + e->y1) - ((e->zoom / 1.3) / 2);
	e->y1 += ((e->zoom / 1.3) / 2) - (e->y2 / (e->zoom / 1.3));
	e->zoom /= 1.3;
	e->it_max -= 5;
}
