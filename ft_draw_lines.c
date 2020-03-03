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


double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		ft_ofset(int iy, int ix, int xy, t_mlx *mlx)
{
	int offset;
	int x;
	int y;
	int z;

	x = mlx->dots[iy][ix].x;
	y = mlx->dots[iy][ix].y;
	z = 0;
	if (mlx->dots[iy][ix].z)
			z = mlx->dots[iy][ix].z + mlx->dots[iy][ix].z / 100 * mlx->stepz;
	if (xy == 0)
		offset = WX / 2 + (x - y) * cos(0.523599);
	else
		offset = WY / 2 + -z + (x + y) * sin(0.523599);
	if (xy == 0 && mlx->projection)
		offset = WX / 2;
	if (xy == 1 && mlx->projection)
		offset = WY / 2;
	return (offset);
}

void	ft_draw_lines(int iy, int ix, int s, t_mlx *mlx)
{
	int x2;
	int y2;

	mlx->dot.x = mlx->dots[iy][ix].x + ft_ofset(iy, ix, 0, mlx);
	mlx->dot.y = mlx->dots[iy][ix].y + ft_ofset(iy, ix, 1, mlx);
	mlx->dot.z = mlx->dots[iy][ix].z;
	mlx->dot.c = mlx->dots[iy][ix].c;
	if ((iy == mlx->my) && (s == 1))
	{
		x2 = mlx->dots[iy][ix].x + ft_ofset(iy, ix, 0, mlx);
		y2 = mlx->dots[iy][ix].y + ft_ofset(iy, ix, 1, mlx);
	}
	if (((ix + 1) != mlx->mx) && s == 0)
	{
		x2 = mlx->dots[iy][ix + 1].x + ft_ofset(iy, ix + 1, 0, mlx);
		y2 = mlx->dots[iy][ix + 1].y + ft_ofset(iy, ix + 1, 1, mlx);
	}
	if (((iy + 1) != mlx->my) && s == 1)
	{
		x2 = mlx->dots[iy + 1][ix].x + ft_ofset(iy + 1, ix, 0, mlx);
		y2 = mlx->dots[iy + 1][ix].y + ft_ofset(iy + 1, ix, 1, mlx);
	}
	ft_draw(y2, x2, mlx);
}
