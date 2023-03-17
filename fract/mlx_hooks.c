/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:49:30 by mbouayou          #+#    #+#             */
/*   Updated: 2023/03/15 17:42:02 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_cross(int keycode, t_var *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_win);
		exit(0);
	}
	return (0);
}

int	ft_close(t_var *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	exit(0);
	return (0);
}

void	ft_shape_check(t_var *fractal)
{
	if (fractal->render_num == 0)
		ft_mandelbrot(fractal);
	else if (fractal->render_num == 1)
		ft_julia(fractal);
}

int	mouse_hook(int keycode, int x, int y, t_var *fractal)
{
	if (keycode == 5)
	{
		x = fractal->origin.o_x;
		y = fractal->origin.o_y;
		fractal->max_iter = 200;
		fractal->scale *= 1.5;
		ft_shape_check(fractal);
	}
	else if (keycode == 4)
	{
		x = fractal->origin.o_x;
		y = fractal->origin.o_y;
		fractal->max_iter = 200;
		fractal->scale *= 0.2;
		ft_shape_check(fractal);
	}
	return (0);
}
