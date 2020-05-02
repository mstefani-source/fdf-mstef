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

void	ft_rotate(t_map *map, t_camera *camera)
{
	int y;
	int x;

	y = 0;
	while (y < map->max_yi)
	{
		x = 0;
		while (x < map->max_xi) {
			rotate_x(&map->dots[y][x], camera->alpha);
			rotate_y(&map->dots[y][x], camera->beta);
			rotate_z(&map->dots[y][x], camera->gamma);
			x++;
		}
		y++;
	}
}

void		ft_final_offset(t_map *map, t_camera *camera)
{
	int y;
	int x;

	y = 0;
	while (y < map->max_yi)
	{
		x = 0;
		while (x < map->max_xi)
		{
			map->dots[y][x].x = (map->dots[y][x].x0) * camera->zoom / 64;
			map->dots[y][x].y = (map->dots[y][x].y0) * camera->zoom / 64;
			if (map->dots[y][x].z0 != 0 || map->dots[y][x].z != 0)
				map->dots[y][x].z = map->dots[y][x].z0 * map->sz / 32 * camera->zoom / 64;
			x++;
		}
		y++;
	}
	ft_getmaxminmid(map, map->dots);
}
