/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:25:20 by mbouayou          #+#    #+#             */
/*   Updated: 2023/03/17 14:58:17 by mbouayou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	ft_norm_atod(char *str, t_atod *va)
{
	if (!((str[va->i] >= '0' && str[va->i] <= '9') || str[va->i] == '.'))
		ft_perror("Error Invalid Sets");
	else if (str[va->i] == '.')
		va->divided = va->i;
	else if (str[va->i] != '.')
		va->res = va->res * 10.0 + str[va->i] - 48.0;
}

double	ft_atoi(char *str)
{
	t_atod	va;

	va.sign = 1.00;
	va.res = 0.0;
	va.i = 0;
	if (!str)
		return (0);
	while (str[va.i] && ((str[va.i] >= 9 && str[va.i] <= 12) || \
		str[va.i] == 32))
		va.i++;
	if (str[va.i++] == '-')
		va.sign *= -1;
	while (str[va.i])
	{
		ft_norm_atod(str, &va);
		va.i++;
	}
	va.res = va.res / pow(10.0, va.i - va.divided - 1);
	return (va.sign * va.res);
}
