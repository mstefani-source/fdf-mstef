/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:58:32 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/20 14:58:38 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(int y2, int x2, t_mlx *mlx)
{
	int dx;
	int dy;
	int err;
	int e2;

	dx = ft_abs(x2 - mlx->dot.x);
	dy = ft_abs(y2 - mlx->dot.y);
	err = dx - dy;
	while ((mlx->dot.x != x2) || (mlx->dot.y != y2))
	{
		mlx_pixel_put(mlx->mlx_p, mlx->wnd, mlx->dot.x, mlx->dot.y, mlx->dot.c);
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
	mlx_pixel_put(mlx->mlx_p, mlx->wnd, mlx->dot.x, mlx->dot.y, mlx->dot.c);
}

void	ft_draw_lines(int iy, int ix, int s, t_mlx *mlx)
{
	int x2;
	int y2;

	mlx->dot.x = mlx->dots[iy][ix].x;
	mlx->dot.y = mlx->dots[iy][ix].y;
	mlx->dot.c = mlx->dots[iy][ix].c;
	if (((ix + 1) == mlx->mx && (s == 0)) || ((iy + 1) == mlx->my && (s == 1)))
	{
		x2 = mlx->dots[iy][ix].x;
		y2 = mlx->dots[iy][ix].y;
	}
	else if (s == 0)
	{
		x2 = mlx->dots[iy][ix + 1].x;
		y2 = mlx->dots[iy][ix + 1].y;
	}
	else
	{
		x2 = mlx->dots[iy + 1][ix].x;
		y2 = mlx->dots[iy + 1][ix].y;
	}
	ft_draw(y2, x2, mlx);
}
