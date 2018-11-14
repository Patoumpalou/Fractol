/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:18:26 by pihouvie          #+#    #+#             */
/*   Updated: 2018/02/01 17:15:27 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

void	mandelbrot_init(t_ftl *e)
{
	e->it_max = 50;
	e->zoom = 300;
	e->x1 = -2.05;
	e->y1 = -1.3;
	e->color = 265;
}

void	draw_mandelbrot(t_ftl *e)
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
		pthread_create(&tabt[i - 1], NULL, mandelbrot, &tab[i - 1]);
	while (i--)
		pthread_join(tabt[i], NULL);
}

void	*mandelbrot(void *tab)
{
	t_ftl	*e;
	double	tmp;

	e = (t_ftl *)tab;
	e->x = 0;
	tmp = e->y;
	while (e->x < WIDTH)
	{
		e->y = tmp;
		while (e->y < e->y_max)
		{
			mandelbrot_bis(e);
			e->y++;
		}
		e->x++;
	}
	return (tab);
}

void	mandelbrot_bis(t_ftl *e)
{
	e->c_r = e->x / e->zoom + e->x1;
	e->c_i = e->y / e->zoom + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	e->it = 0;
	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->it < e->it_max)
	{
		e->tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * e->tmp + e->c_i;
		e->it++;
	}
	if (e->it == e->it_max)
		ft_put_pxl(e, e->x, e->y, 0x000000);
	else
		ft_put_pxl(e, e->x, e->y, (e->color * e->it));
}
