/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:59:19 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/26 17:59:26 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void ft_print_menu(t_mlx *mlx)
{
    mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  300, RED,  "map->sz/32 = " );
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 100, 300, RED,  ft_itoa(mlx->map->sz/32));

	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  315, RED,  "offset_y = " );
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 70, 315, RED,  ft_itoa(mlx->camera->offset_y));

	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  330, RED,  "maxz = " );
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 50, 330, RED,  ft_itoa(mlx->map->max_z));
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  345, RED,  "minz = " );
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 50, 345, RED,  ft_itoa(mlx->map->min_z));
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  360, RED,  "midz = " );
	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 50, 360, RED,  ft_itoa(mlx->map->mid_z));


	mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  375, RED,  "zoom = " );
    mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 50, 375, RED,  ft_itoa(mlx->camera->zoom + 36));

    mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 5,  390, RED,  "PROJECTION = " );
    mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, 80, 390, RED,  ft_itoa(mlx->camera->projection));


}

void  	ft_set_angle(t_mlx *mlx, int key)
{
	if (key == ZROTATE1)
		mlx->camera->gamma += 0.05;
	if (key == ZROTATE2)
		mlx->camera->gamma -= 0.05;
	if (key == YROTATE1)
		mlx->camera->beta += 0.05;
	if (key == YROTATE2)
		mlx->camera->beta -= 0.05;
	if (key == XROTATE1)
		mlx->camera->alpha += 0.05;
	if (key == XROTATE2)
		mlx->camera->alpha -= 0.05;
}

int		ft_key_win(int key, t_mlx *mlx)
{
	write(1, "Key pressed : ", 14);
	ft_putnbr(key);
	write(1, "\n", 1);
	if (key == 65307)
	{
		mlx_destroy_window(mlx->wnd->ptr, mlx->wnd->wnd);
		free(mlx);
		exit(0);
	}
	else if (key == ARROW_LEFT || key == ARROW_RIGHT \
		|| key == ARROW_UP || key == ARROW_DOWN)
		ft_move(key, mlx);
	else if (key == ISO_KEY)
		mlx->camera->projection = ISO;
	else if (key == PARALLEL_KEY)
		mlx->camera->projection = PARALLEL;
	else if (key == RIZE_KEY) {
		mlx->map->sz += STEPZ;
	}
	else if (key == FALL_KEY) {
		mlx->map->sz -= STEPZ;
	}

	else if (key == XROTATE1 || key == XROTATE2 \
		|| key == YROTATE1 || key == YROTATE2 \
		|| key == ZROTATE1 || key == ZROTATE2)
		ft_set_angle(mlx, key);

	if (key == CLEAR_WINDOW) {
		mlx_clear_window(mlx->wnd->ptr, mlx->wnd->wnd);
	}
	ft_final_offset(mlx->map, mlx->camera);
	ft_rotate(mlx->map, mlx->camera);
	ft_transform(mlx);
	ft_draw_map(mlx->wnd, mlx->map);
	ft_print_menu(mlx);
	return (0);
}
