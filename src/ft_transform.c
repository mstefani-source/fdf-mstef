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

void	ft_iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	ft_transform(t_mlx* mlx)
{
	int y;
	int x;

	y = 0;
	if (mlx->camera->projection == ISO)
	{
	while (y < mlx->map->max_yi)
	{
		x = 0;
		while (x < mlx->map->max_xi)
		{
			ft_iso(&mlx->map->dots[y][x].x, &mlx->map->dots[y][x].y, mlx->map->dots[y][x].z);
			x++;
		}
		y++;
	}
	}
}
