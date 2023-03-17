/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:07 by mbouayou          #+#    #+#             */
/*   Updated: 2023/03/17 14:28:32 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_guide(void)
{
	ft_putstr("**************************************\n");
	ft_putstr("**            Fract-Guide           **\n");
	ft_putstr("**         option 1: Mandelbrot     **\n");
	ft_putstr("**         option 2: Julia          **\n");
	ft_putstr("** To Render another Julia put sets **\n");
	ft_putstr("**************************************\n");
}

void	ft_check_to_render(t_var *fractol, char **str, int param)
{
	if (!ft_strcmp(str[1], "Mandelbrot"))
	{
		fractol->render_num = 0;
		fractol->max_iter = 200;
		fractol->scale = 250;
		ft_mandelbrot(fractol);
	}
	else if (!ft_strcmp(str[1], "Julia"))
	{
		fractol->render_num = 1;
		fractol->max_iter = 200;
		fractol->scale = 250;
		if (param == 2)
		{
			fractol->c_x = 0.285;
			fractol->c_y = 0.01;
		}
		else if (param == 4)
		{
			fractol->c_x = ft_atoi(str[2]);
			fractol->c_y = ft_atoi(str[3]);
		}
		ft_julia(fractol);
	}
}

void	ft_norm(t_var *fractol, char **str, int param)
{
	fractol->mlx = mlx_init();
	fractol->data.img = mlx_new_image(fractol->mlx, 1000, 1000);
	fractol->data.addr = mlx_get_data_addr(fractol->data.img, \
		&fractol->data.bits_per_pixel, \
			&fractol->data.line_length, &fractol->data.endian);
	fractol->mlx_win = mlx_new_window(fractol->mlx, W_SCREEN, H_SCREEN, \
		"ft_fractol!");
	origine(fractol, W_SCREEN, W_SCREEN);
	ft_check_to_render(fractol, str, param);
}

void	ft_pars(t_var *fract, int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
			ft_norm(fract, av, ac);
		else if (ft_strcmp(av[1], "Julia") == 0)
			ft_norm(fract, av, ac);
		else
			ft_guide_err();
	}
	else if (ac == 4)
	{
		if (ft_strcmp(av[1], "Julia") == 0)
			ft_norm(fract, av, ac);
		else
			ft_guide_err();
	}
	else
	{
		if (ac == 1)
			return ;
		else
			ft_perror("Error ARGs");
	}
}

int	main(int ac, char **av)
{
	t_var	fract;

	ft_pars(&fract, ac, av);
	mlx_hook(fract.mlx_win, 17, 0, ft_close, &fract);
	mlx_hook(fract.mlx_win, 2, 0, ft_cross, &fract);
	mlx_mouse_hook(fract.mlx_win, mouse_hook, &fract);
	mlx_loop(fract.mlx);
}
