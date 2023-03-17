/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:13:49 by mbouayou          #+#    #+#             */
/*   Updated: 2023/03/17 14:27:26 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define H_SCREEN 1000
# define W_SCREEN 1000

typedef struct s_atod
{
	double	res;
	double	sign;
	int		i;
	int		divided;
}	t_atod;

typedef struct s_sets
{
	double	set_x;
	double	set_y;
}	t_sets;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	
}	t_data;

typedef struct s_origin
{
	double	o_x;
	double	o_y;
}	t_origin;

typedef struct s_var{
	void			*mlx;
	void			*mlx_win;			
	int				render_num;
	int				rgb_color;
	unsigned int	iter;
	unsigned int	max_iter;
	double			z_x;
	double			z_y;
	double			c_x;
	double			c_y;
	double			x;
	double			y;
	double			scale;
	double			tmp;
	t_data			data;
	t_origin		origin;
}	t_var;

void	my_mlx_pixel_put(t_var *data, int x, int y, int color);

void	ft_norm(t_var *fractol, char **str, int param);

void	ft_mandelbrot(t_var *fract);
void	ft_julia(t_var *fract);

int		ft_close(t_var *fractal);
int		mouse_hook(int keycode, int x, int y, t_var *fractal);
int		ft_cross(int keycode, t_var *fractal);

void	ft_shape_check(t_var *fractal);

void	convert_int_to_rgb(t_var *fractal);
void	ft_render(t_var *fractal);
void	origine(t_var *fractal, int x, int y);

void	ft_perror(char *str);
void	ft_guide_err(void);
void	ft_guide(void);

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
double	ft_atoi(char *str);

#endif