/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:13:44 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/19 17:13:56 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_mlx *mlx)
{
	int dx;
	int dy;
	int err;
	int e2;
	int x = 0;
	int y = 0;
	
	while (y != mlx->mapsy)
	{
		while (x != mlx->mapsx)
		{
							 y	x      y  x+1
			рисуем линию от [0][0] к  [0] [1]
							 y  x	  y+1  x
			рисуем линию от [0][0] к  [1] [0]
			x++;
		}
		x = 0;
		y++;
	}
	
	dx = ft_abs(x2 - mlx->dot.x);
	dy = ft_abs(y2 - mlx->dot.y);
	err = dx - dy;
	while ((mlx->dot.x != x2) || (mlx->dot.y != y2))
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->dot.x, mlx->dot.y, mlx->dot.color);
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
}