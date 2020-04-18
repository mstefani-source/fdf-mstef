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

#include "../fdf.h"

static void	draw_background(t_mlx *mlx)
{
	int	*image;
	int	i;

	ft_bzero(mlx->wnd->data_addr, WX * WY * (mlx->wnd->bit_per_pixel / 8));
	image = (int *)(mlx->wnd->data_addr);
	i = 0;
	while (i < (WY * WX))
	{
		image[i] = BACKGROUND;
		i++;
	}
}

void ft_print_coord(t_mlx *mlx)
{
	int y;
	int x;

	y = 0;
	while (y < mlx->my)
	{
		x = 0;
		while (x < mlx->mx)
		{
			mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, mlx->dots[y][x].x,	mlx->dots[y][x].y, RED, ft_itoa(mlx->dots[y][x].x));
			mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, mlx->dots[y][x].x,	mlx->dots[y][x].y + 10, RED, ft_itoa(mlx->dots[y][x].y));
			mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, mlx->dots[y][x].x,	mlx->dots[y][x].y + 20, RED, ft_itoa(mlx->dots[y][x].z));

			mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, mlx->dots[y][x].x0,mlx->dots[y][x].y0, BLUE, ft_itoa(mlx->dots[y][x].x0));
			mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, mlx->dots[y][x].x0,mlx->dots[y][x].y0 + 10, BLUE, ft_itoa(mlx->dots[y][x].y0));
			mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, mlx->dots[y][x].x0,mlx->dots[y][x].y0 + 20, BLUE, ft_itoa(mlx->dots[y][x].z0));

			x++;
		}
		y++;
	}
}

void ft_print_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  315, RED,  "offset_y = " );
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 70, 315, RED,  ft_itoa(mlx->camera->offset_y));

    mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  300, RED,  "mlx->stepz/32 = " );
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 100, 300, RED,  ft_itoa(mlx->stepz/32));

	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  330, RED,  "maxz = " );
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 50, 330, RED,  ft_itoa(mlx->maxz));
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  345, RED,  "minz = " );
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 50, 345, RED,  ft_itoa(mlx->minz));

	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  360, RED,  "zoom = " );
    mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 50, 360, RED,  ft_itoa(mlx->camera->zoom + 36));

    mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  377, RED,  "PROJECTION = " );
    mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 80, 377, RED,  ft_itoa(mlx->camera->projection));
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
 			ft_draw_line(iy, ix, 0, mlx);
			ft_draw_line(iy, ix, 1, mlx);
			ix++;
		}
		ft_draw_line(iy, ix, 1, mlx);
		iy++;
	}
	mlx_put_image_to_window(mlx->wnd->ptr, mlx->wnd->wnd, mlx->wnd->img, 0, 0);
	ft_print_menu(mlx);
	ft_print_coord(mlx);
}
