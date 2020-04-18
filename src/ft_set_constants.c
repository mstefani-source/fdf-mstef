/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_constants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:23:45 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/09 18:25:54 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fdf.h"


void    ft_fzero(t_dot *dots, int y, int x, t_mlx *mlx)
{
	int	i;

    i = 0;
	while (x - i)
	{
		dots[i].x0 = dots[i].x = 4 * mlx->x0 + (i * WX / (x));
		dots[i].y0 = dots[i].y = 4 * mlx->y0 + (y * WY / (mlx->my));
		dots[i].z0 = dots[i].z = 0;
		dots[i].c0 = dots[i].c = COLOR_DEFAULT_MIN;
		i++;
	}
}

void 		ft_set_constants(t_mlx *mlx)
{
	mlx->minz = 0;
	mlx->maxz = 0;
	mlx->stepx = WX / (2 * mlx->mx);
	mlx->stepy = WY / (2 * mlx->my);
	mlx->stepz = 32;
	mlx->x0 = 0 - (mlx->mx * mlx->stepx - mlx->stepx) / 4;
	mlx->y0 = 0 - (mlx->my * mlx->stepy - mlx->stepy) / 4;
	mlx->camera = camera_init();
	mlx->line = line_init();
	mlx->dot = dot_init();
}