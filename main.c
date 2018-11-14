/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:16:16 by pihouvie          #+#    #+#             */
/*   Updated: 2018/02/01 17:06:37 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftl.h"

void	fract_init(t_ftl *e)
{
	if (ft_strcmp(e->input, "julia") == 0)
		julia_init(e);
	else if (ft_strcmp(e->input, "mandelbrot") == 0)
		mandelbrot_init(e);
	else if (ft_strcmp(e->input, "burningship") == 0)
		burningship_init(e);
	else
		ft_exit("Nom incorrect");
}

int		expose_hook(t_ftl *e)
{
	draw_reload(e);
	return (0);
}

void	draw_reload(t_ftl *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, WIDTH);
	e->str_img = mlx_get_data_addr(e->img,
			&e->img3[0], &e->img3[1], &e->img3[2]);
	pick_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

int		main(int ac, char **ag)
{
	t_ftl	e;

	if (ac == 2)
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIDTH, WIDTH, "Fractol");
		ft_display();
		e.input = ag[1];
		fract_init(&e);
		mlx_hook(e.win, 2, 5, key_hook, &e);
		mlx_hook(e.win, 6, 5, mouse_julia, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_exit("Usage: ./fractol \"mandelbrot\", \"julia\", \"burningship\"");
	return (0);
}
