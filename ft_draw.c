/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:11:10 by mstefani          #+#    #+#             */
/*   Updated: 2020/03/03 22:11:12 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double 	ft_length(int x2, int y2, t_dot start_dot)
{

	return (sqrt(pow(x2 - start_dot.x,2) + pow(y2 - start_dot.y, 2)));
}

int		ft_calc_color(t_dot start_dot, int x2, int y2, double len)
{
	int			new_color;
	double		percent;

	percent = ft_length(x2 ,y2, start_dot) / len * 100;
	new_color = percent * COLOR_DEFAULT;

	return (new_color);
}

void	ft_draw(int y2, int x2, t_mlx *mlx)
{
	int dx;
	int dy;
	int err;
	int e2;

	dx = ft_abs(x2 - mlx->dot.x);
	dy = ft_abs(y2 - mlx->dot.y);
//	mlx->len = ft_length(x2,y2,mlx->dot);
	err = dx - dy;
	while ((mlx->dot.x != x2) || (mlx->dot.y != y2))
	{
		mlx->dot.c = ft_calc_color(mlx->dot, x2, y2, ft_length(x2,y2,mlx->dot));
		ft_put_pixel(mlx->dot.x, mlx->dot.y, mlx->dot.c, mlx);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			mlx->dot.x += STEP(mlx->dot.x, x2);
		}
		if (e2 < dx)
		{
			err += dx;
			mlx->dot.y += STEP(mlx->dot.y, y2);
		}
	}
	ft_put_pixel(mlx->dot.x, mlx->dot.y, mlx->dot.c, mlx);
}

