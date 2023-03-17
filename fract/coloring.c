/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:03:25 by mbouayou          #+#    #+#             */
/*   Updated: 2023/03/16 22:50:39 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	convert_int_to_rgb(t_var *fractal)
{
	t_color	color;

	color.red = sin(fractal->iter / 50.0) * (127 + 20);
	color.green = sin(fractal->iter / 80.0) * (127 + 20);
	color.blue = sin(fractal->iter / 110.0) * (127 + 20);
	fractal->rgb_color = color.red << 16 | color.green << 8 | color.blue;
}
