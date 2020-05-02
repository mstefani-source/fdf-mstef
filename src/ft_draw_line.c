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

//void 	ft_discover_line(t_line *line, t_map *map)
//{
//	double percent;
//
//	line->dz = 0;
//	if (line->z1 < line->z0)
//		line->dz = -1;
//	if (line->z1 > line->z0)
//		line->dz = 1;
//	percent = ft_percent(map->min_z, map->max_z, line->c0);
//	line->start_color = rgb_to_int((255 / 100) * percent, 153, 0);
//}


//void	ft_draw_line_old(int iy, int ix, int s, t_mlx *mlx)
//{
//	int x2;
//	int y2;
//
//	mlx->dot->x = mlx->dots[iy][ix].x + mlx->camera->offset_x + WX / 2;
//	mlx->dot->y = mlx->dots[iy][ix].y + mlx->camera->offset_y + WY / 2;
//	mlx->dot->z = mlx->dots[iy][ix].z;
//	mlx->dot->z0 = mlx->dots[iy][ix].z0;
//	mlx->dot->c = mlx->dots[iy][ix].c;
//	if (((ix + 1) != mlx->mx) && s == 0)
//	{
//		x2 = mlx->dots[iy][ix + 1].x + mlx->camera->offset_x + WX / 2;
//		y2 = mlx->dots[iy][ix + 1].y + mlx->camera->offset_y + WY / 2;
//		ft_discover_line(iy, ix + 1, mlx);
//	}
//	if (((iy + 1) != mlx->my) && s == 1)
//	{
//		x2 = mlx->dots[iy + 1][ix].x + mlx->camera->offset_x + WX / 2;
//		y2 = mlx->dots[iy + 1][ix].y + mlx->camera->offset_y + WY / 2;
//		ft_discover_line(iy + 1, ix, mlx);
//	}
//	mlx->line->length = ft_length(x2 , y2, mlx->dot->x, mlx->dot->y);
//	ft_draw(y2, x2, mlx);
//}


	