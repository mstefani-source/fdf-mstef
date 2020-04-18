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
		mlx->stepz += STEPZ;
	}
	else if (key == FALL_KEY) {
		mlx->stepz -= STEPZ;
	}

	else if (key == XROTATE1 || key == XROTATE2 \
		|| key == YROTATE1 || key == YROTATE2 \
		|| key == ZROTATE1 || key == ZROTATE2)
		ft_set_angle(mlx, key);

	if (key == CLEAR_WINDOW) {
		mlx_clear_window(mlx->wnd->ptr, mlx->wnd->wnd);
	}
	ft_final_offset(mlx);
	ft_rotate(mlx);
	ft_transform(mlx);
	ft_draw_map(mlx);
	return (0);
}
