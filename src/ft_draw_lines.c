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

#include "../fdf.h"

int		rotate_x(int iy, int ix, int xy, t_mlx *mlx)
{
	int		offset;
	int		z;
	int		y;

	y = mlx->dots[iy][ix].y;
	z = mlx->dots[iy][ix].z;

	if (xy == 0)
		offset = y * cos(mlx->camera.alpha) + z * sin(mlx->camera.alpha);
	else
		offset = -y * sin(mlx->camera.alpha) + z * cos(mlx->camera.alpha);
	return (offset);
}

int		rotate_y(int iy, int ix, int xy, t_mlx *mlx)
{
	int		offset;
	int		x;
	int		z;

	x = mlx->dots[iy][ix].x;
	z = mlx->dots[iy][ix].z;

	if (xy == 0)
		offset = x * cos(mlx->camera.beta) + z * sin(mlx->camera.beta);
	else
		offset = -x * sin(mlx->camera.beta) + z * cos(mlx->camera.beta);
	return (offset);
}

int		rotate_z(int iy, int ix, int xy, t_mlx *mlx)
{
	int		offset;
	int		x;
	int		y;

	x = mlx->dots[iy][ix].x;
	y = mlx->dots[iy][ix].y;

	if (xy == 0)
		offset = x * cos(mlx->camera.gamma) - y * sin(mlx->camera.gamma);
	else
		offset = y * sin(mlx->camera.gamma) + y * cos(mlx->camera.gamma);
	return (offset);
}

int		ft_ofset(int iy, int ix, int xy, t_mlx *mlx)
{
	int		offset;
	int		x;
	int		y;
	double	z;

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

int		ft_rotata(int iy, int ix, t_mlx *mlx)
{
	mlx->dot.x = mlx->dots[iy][ix].x + rotate_x(iy, ix, 0, mlx);
	mlx->dot.y = mlx->dots[iy][ix].y + rotate_x(iy, ix, 1, mlx);

	mlx->dot.x = mlx->dot.x + rotate_y(iy, ix, 0, mlx);
	mlx->dot.y = mlx->dot.y + rotate_y(iy, ix, 1, mlx);

	mlx->dot.x = mlx->dot.x + rotate_z(iy, ix, 0, mlx);
	mlx->dot.y = mlx->dot.y + rotate_z(iy, ix, 1, mlx);

	return (0);
}

void	ft_mlxholddot(t_mlx *mlx, int iy, int ix)
{
	ft_rotata(iy, ix, mlx);
	mlx->dot.x = mlx->dot.x + ft_ofset(iy, ix, 0, mlx);
	mlx->dot.y = mlx->dot.y + ft_ofset(iy, ix, 1, mlx);
	mlx->dot.z = mlx->dots[iy][ix].z;

//	mlx->dot.c = mlx->dots[iy][ix].c;
}

void	ft_draw_lines(int iy, int ix, int s, t_mlx *mlx)
{
	int x2;
	int y2;


	mlx->dot.x = mlx->dots[iy][ix].x + rotate_z(iy, ix, 0, mlx);
	mlx->dot.y = mlx->dots[iy][ix].y + rotate_z(iy, ix, 1, mlx);

	mlx->dot.x = mlx->dot.x + ft_ofset(iy, ix, 0, mlx);
	mlx->dot.y = mlx->dot.y + ft_ofset(iy, ix, 1, mlx);
	mlx->dot.z = mlx->dots[iy][ix].z;

/*	x2 = mlx->dots[iy][ix].x + rotate_z(iy, ix, 0, mlx);
	y2 = mlx->dots[iy][ix].y + rotate_z(iy, ix, 1, mlx);

	x2 = x2 + ft_ofset(iy, ix, 0, mlx);
	y2 = y2 + ft_ofset(iy, ix, 1, mlx);*/

	if (((ix + 1) != mlx->mx) && s == 0)
	{
		x2 = mlx->dots[iy][ix + 1].x + rotate_z(iy, ix + 1, 0, mlx);
		y2 = mlx->dots[iy][ix + 1].y + rotate_z(iy, ix + 1, 1, mlx);

//		ft_rotata(iy,ix + 1, mlx);

		x2 = x2 + ft_ofset(iy, ix + 1, 0, mlx);
		y2 = y2 + ft_ofset(iy, ix + 1, 1, mlx);

		mlx->dot.z = mlx->dots[iy][ix + 1].z;
	}
	if (((iy + 1) != mlx->my) && s == 1)
	{
		x2 = mlx->dots[iy + 1][ix].x + rotate_z(iy + 1, ix, 0, mlx);
		y2 = mlx->dots[iy + 1][ix].y + rotate_z(iy + 1, ix, 1, mlx);

//		ft_rotata(iy + 1,ix, mlx);

		x2 = x2 + ft_ofset(iy + 1, ix, 0, mlx);
		y2 = y2 + ft_ofset(iy + 1, ix, 1, mlx);

		mlx->dot.z = mlx->dots[iy + 1][ix].z;
	}
	mlx->dot.dz = ft_abs(mlx->dots[iy][ix].z - mlx->dot.z);
	ft_draw(y2, x2, mlx);
}
