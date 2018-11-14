/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:37:32 by pihouvie          #+#    #+#             */
/*   Updated: 2018/02/01 16:27:40 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

int		mouse_julia(int x, int y, t_ftl *e)
{
	if (e->julia_mouse == 1 && e->stop == 0)
	{
		e->c_r = x * 2;
		e->c_i = y * 2 - 800;
		draw_reload(e);
	}
	return (0);
}

void	julia_init(t_ftl *e)
{
	e->stop = 0;
	e->it_max = 100;
	e->zoom = 200;
	e->x1 = -2.0;
	e->y1 = -1.9;
	e->color = 115700;
	e->c_r = 0.285;
	e->c_i = 0.01;
	e->julia_mouse = 1;
}

void	draw_julia(t_ftl *e)
{
	t_ftl		tab[WIDTH / 100];
	pthread_t	tabt[WIDTH / 100];
	int			i;
	int			size;

	size = WIDTH / 100;
	i = 0;
	while (i < size)
	{
		ft_memcpy((void*)&tab[i], (void*)e, sizeof(t_ftl));
		tab[i].y = 100 * i;
		tab[i].y_max = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= size)
		pthread_create(&tabt[i - 1], NULL, julia, &tab[i - 1]);
	while (i--)
		pthread_join(tabt[i], NULL);
}

void	*julia(void *tab)
{
	double	tmp;
	t_ftl	*e;

	e = (t_ftl *)tab;
	e->x = 0;
	tmp = e->y;
	while (e->x < WIDTH)
	{
		e->y = tmp;
		while (e->y < e->y_max)
		{
			julia_bis(e);
			e->y++;
		}
		e->x++;
	}
	return (tab);
}

void	julia_bis(t_ftl *e)
{
	e->z_r = e->x / e->zoom + e->x1;
	e->z_i = e->y / e->zoom + e->y1;
	e->it = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->it < e->it_max)
	{
		e->tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i - 0.8 + (e->c_r / WIDTH);
		e->z_i = 2 * e->z_i * e->tmp + e->c_i / WIDTH;
		e->it++;
	}
	if (e->it == e->it_max)
		ft_put_pxl(e, e->x, e->y, 0xFFFFFF);
	else
		ft_put_pxl(e, e->x, e->y, (e->color * e->it));
}
