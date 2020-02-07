/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:40:47 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/05 18:40:55 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_plot_line(int x2, int y2, t_mlx *mlx)
{
	int dx;
	int dy;
	int err;
	int e2;

	dx = ft_abs(x2 - mlx->sx);
	dy = ft_abs(y2 - mlx->sy);
	err = dx - dy;
	while ((mlx->sx != x2) || (mlx->sy != y2))
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->sx, mlx->sy, BLUE);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			mlx->sx += STEP(mlx->sx, x2);
		}
		if (e2 < dx)
		{
			err += dx;
			mlx->sy += STEP(mlx->sy, y2);
		}
	}
	return (0);
}
