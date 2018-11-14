/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:26:44 by pihouvie          #+#    #+#             */
/*   Updated: 2018/02/01 16:57:27 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

void	ft_display(void)
{
	ft_putendl("	BONUS\n\n\
	---------------------------\n\
	zoom sur le curseur de la souris\n\n\
	Espace pour reset\n\n\
	pav num '+' et '-' pour modifier la precision\n\n\
	Fleches directionnelles\n\n\
	Clic gauche et droit pour zoomer/in\n\n\
	's' pour figer la fractale de julia\n\n\
	---------------------------");
}

void	pick_draw(t_ftl *e)
{
	if (ft_strcmp(e->input, "julia") == 0)
		draw_julia(e);
	else if (ft_strcmp(e->input, "mandelbrot") == 0)
		draw_mandelbrot(e);
	else if (ft_strcmp(e->input, "burningship") == 0)
		draw_burningship(e);
}

void	ft_put_pxl(t_ftl *e, int x, int y, int color)
{
	int px;

	px = (x * 4) + (y * e->img3[1]);
	if (px >= 0 && px < WIDTH * WIDTH * 4 + 1)
	{
		if ((x > 0 && x < WIDTH) && (y > 0 && y < WIDTH))
		{
			e->str_img[px] = color;
			e->str_img[px + 1] = color >> 8;
			e->str_img[px + 2] = color >> 16;
		}
	}
}
