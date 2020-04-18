/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:56:33 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/25 16:56:36 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void 	rotate_x(t_dot *dot, double alpha)
{
	int previous_y;

	previous_y = dot->y;
	dot->y = previous_y * cos(alpha) + dot->z * sin(alpha);
	dot->z = -previous_y * sin(alpha) + dot->z * cos(alpha);
}

static void 	rotate_y(t_dot *dot, double beta)
{
	int previous_x;

	previous_x = dot->x;
	dot->x = previous_x * cos(beta) + dot->z * sin(beta);
	dot->z = -previous_x * sin(beta) + dot->z * cos(beta);
}

static void		rotate_z(t_dot *dot, double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = dot->x;
	previous_y = dot->y;
	dot->x = previous_x * cos(gamma) - previous_y * sin(gamma);
	dot->y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void		ft_final_offset(t_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->my)
	{
		x = 0;
		while (x < mlx->mx)
		{
			mlx->dots[y][x].x = (mlx->dots[y][x].x0) * mlx->camera->zoom / 64;
			mlx->dots[y][x].y = (mlx->dots[y][x].y0) * mlx->camera->zoom / 64;
			if (mlx->dots[y][x].z0 != 0 || mlx->dots[y][x].z != 0)
			{
				mlx->dots[y][x].z = mlx->dots[y][x].z0 * mlx->stepz / 32 * mlx->camera->zoom / 64;
				ft_getmaxmin(mlx, mlx->dots);
			}
			x++;
		}
		y++;
	}
}

void	ft_rotate(t_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->my)
	{
		x = 0;
		while (x < mlx->mx) {
			rotate_x(&mlx->dots[y][x], mlx->camera->alpha);
			rotate_y(&mlx->dots[y][x], mlx->camera->beta);
			rotate_z(&mlx->dots[y][x], mlx->camera->gamma);
			x++;
		}
		y++;
	}
}