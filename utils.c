/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:13:57 by mbouayou          #+#    #+#             */
/*   Updated: 2023/03/17 10:36:12 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_var *fractal, int x, int y, int color)
{
	char	*dst;

	if (x < W_SCREEN && y < H_SCREEN)
	{
		dst = fractal->data.addr + (y * fractal->data.line_length + x
				* (fractal->data.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	origine(t_var *fractal, int x, int y)
{
	fractal->origin.o_x = x / 2;
	fractal->origin.o_y = y / 2;
}

void	ft_render(t_var *fractal)
{
	while ((fractal->z_x * fractal->z_x) + (fractal->z_y * fractal->z_y) < 4.0 \
		&& fractal->iter < fractal->max_iter)
	{
		fractal->tmp = fractal->z_x;
		fractal->z_x = (fractal->z_x * fractal->z_x) - \
			(fractal->z_y * fractal->z_y) + fractal->c_x;
		fractal->z_y = 2 * fractal->tmp * fractal->z_y + fractal->c_y;
		fractal->iter++;
	}
	if (fractal->iter == fractal->max_iter)
		my_mlx_pixel_put(fractal, fractal->origin.o_x + fractal->x, \
			fractal->origin.o_y - fractal->y, 0);
	else
	{
		convert_int_to_rgb(fractal);
		my_mlx_pixel_put(fractal, fractal->origin.o_x + fractal->x, \
			fractal->origin.o_y - fractal->y, fractal->rgb_color);
	}
}
