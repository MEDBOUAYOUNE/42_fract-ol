/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:18 by mbouayou          #+#    #+#             */
/*   Updated: 2023/03/15 17:51:19 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_var *fract)
{
	fract->y = -2.0 * (H_SCREEN / 4);
	while (fract->y <= 2.0 * (H_SCREEN / 4))
	{
		fract->x = -2.0 * (W_SCREEN / 4);
		fract->c_y = fract->y / fract->scale;
		while (fract->x <= 2.0 * (W_SCREEN / 4))
		{
			fract->z_x = fract->x / fract->scale;
			fract->z_y = fract->y / fract->scale;
			fract->c_x = fract->x / fract->scale;
			fract->iter = 0;
			ft_render(fract);
			fract->x++;
		}
		fract->y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->data.img, 0, 0);
}
