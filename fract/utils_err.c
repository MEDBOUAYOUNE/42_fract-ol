/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:23:12 by mbouayou          #+#    #+#             */
/*   Updated: 2023/03/17 14:29:35 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_guide_err(void)
{
	ft_guide();
	exit(1);
}

void	ft_perror(char *str)
{
	if (!str)
	{
		ft_putstr("Error");
		exit(1);
	}
	else
	{
		ft_putstr(str);
		exit(1);
	}
}
