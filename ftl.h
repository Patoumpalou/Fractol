/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:20:00 by pihouvie          #+#    #+#             */
/*   Updated: 2018/02/01 16:57:54 by pihouvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTL_H
# define FTL_H

# include <mlx.h>
# include <math.h>
# include "libft/libft.h"
# include <pthread.h>
# define WIDTH 800

typedef struct	s_ftl
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*str_img;
	int			img3[3];
	char		*input;
	int			color;
	int			stop;
	int			julia_mouse;
	double		zoom;
	double		it_max;
	double		x2;
	double		y2;
	double		x1;
	double		y1;
	double		x;
	double		y;
	double		y_max;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		it;
	double		tmp;
}				t_ftl;

void			fract_init(t_ftl *e);
int				expose_hook(t_ftl *e);
void			draw_reload(t_ftl *e);

void			ft_display(void);
void			pick_draw(t_ftl *e);
void			ft_put_pxl(t_ftl *e, int x, int y, int color);

int				mouse_julia(int x, int y, t_ftl *e);
void			julia_init(t_ftl *e);
void			draw_julia(t_ftl *e);
void			*julia(void *tab);
void			julia_bis(t_ftl *e);

void			mandelbrot_init(t_ftl *e);
void			draw_mandelbrot(t_ftl *e);
void			*mandelbrot(void *tab);
void			mandelbrot_bis(t_ftl *e);

int				key_hook(int keycode, t_ftl *e);
int				mouse_hook(int mousecode, int x, int y, t_ftl *e);
void			ft_zoom(int x, int y, t_ftl *e);
void			ft_dezoom(t_ftl *e);

void			burningship_init(t_ftl *e);
void			draw_burningship(t_ftl *e);
void			*burningship(void *tab);
void			burningship_bis(t_ftl *e);

#endif
