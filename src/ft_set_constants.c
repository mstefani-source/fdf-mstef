/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_constants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:23:45 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/25 21:09:14 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_fzero(t_dot *dots, int y, int x, t_map *map)
{
	int	i;

	i = 0;
	while (x - i)
	{
		dots[i].x = 4 * map->x0 + (i * WX / (x));
		dots[i].x0 = dots[i].x;
		dots[i].y = 4 * map->y0 + (y * WY / (map->max_yi));
		dots[i].y0 = dots[i].y;
		dots[i].z = 0;
		dots[i].z0 = dots[i].z;
		dots[i].color = map->color_min;
		i++;
	}
}

void	ft_set_constants(t_mlx *mlx)
{
	mlx->map = map_init();
	mlx->line = line_init();
	mlx->dot = dot_init();
	mlx->camera = camera_init();
}
