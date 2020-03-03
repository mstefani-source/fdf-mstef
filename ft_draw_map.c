/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:13:44 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/19 17:13:56 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_background(t_mlx *mlx)
{
	int	*image;
	int	i;

	ft_bzero(mlx->data_addr, WX * WY * (mlx->bit_per_pixel / 8));
	image = (int *)(mlx->data_addr);
	i = 0;
	while (i < WY * WX)
	{
		image[i] = BACKGROUND;
		i++;
	}
}

void	ft_draw_map(t_mlx *mlx)
{
	int ix;
	int iy = 0;

	draw_background(mlx);
	while (iy < mlx->my)
	{
		ix = 0;
		while (ix < mlx->mx - 1)
		{
			ft_draw_lines(iy, ix, 0, mlx);
			ft_draw_lines(iy, ix, 1, mlx);
			ix++;
		}
		ft_draw_lines(iy, ix, 1, mlx);
		iy++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->wnd, mlx->img, 0, 0);
}
