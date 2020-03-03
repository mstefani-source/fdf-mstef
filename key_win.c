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

#include "fdf.h"

void ft_mlx_up(t_mlx *mlx)
{
	int x = 0;
	int y = 0;

	while (y < mlx->my)
	{
		while (x < mlx->mx)
		{
			mlx->dots[y][x].y -= 10;
			x++;
		}
		x = 0;
		y++;
	}
}

void ft_mlx_down(t_mlx *mlx)
{
	int x = 0;
	int y = 0;

	while (y < mlx->my)
	{
		while (x < mlx->mx)
		{
			mlx->dots[y][x].y += 10;
			x++;
		}
		x = 0;
		y++;
	}
}

void ft_mlx_right(t_mlx *mlx)
{
	int x = 0;
	int y = 0;

	while (y < mlx->my)
	{
		while (x < mlx->mx)
		{
			mlx->dots[y][x].x += 10;
			x++;
		}
		x = 0;
		y++;
	}
}

void ft_mlx_left(t_mlx *mlx)
{
	int x = 0;
	int y = 0;

	while (y < mlx->my)
	{
		while (x < mlx->mx)
		{
			mlx->dots[y][x].x -= 10 ;
			x++;
		}
		x = 0;
		y++;
	}
}

int		key_win(int key, t_mlx *mlx)
{
	write(1, "Key pressed : ", 14);
	ft_putnbr(key);
	write(1, "\n", 1);
	if (key == 53)
	{
		close(mlx->fd);
		free(mlx);
		exit(0);
	}
	if (key == 124)
	{
		ft_mlx_right(mlx);
		ft_draw_map(mlx);
	}
	else if (key == 126)
	{
		ft_mlx_up(mlx);
//		mlx->stepz = mlx->stepz + 10;
		ft_draw_map(mlx);;
	}
	else if (key == 125)
	{
		ft_mlx_down(mlx);
//		mlx->stepz = mlx->stepz - 10;
		ft_draw_map(mlx);
	}
	else if (key == 123) {
		ft_mlx_left(mlx);
		ft_draw_map(mlx);
	}
	else if (key == 34) {
		mlx->projection = ISO;
		ft_draw_map(mlx);
		mlx_string_put(mlx->ptr, mlx->wnd, 10, 10, 16777046, "ISO");
	}
	else if (key == 35) {
		mlx->projection = PARALLEL;
		ft_draw_map(mlx);
		mlx_string_put(mlx->ptr, mlx->wnd, 10, 10, 16777046, "PARALLEL" );
	}
	else if (key == 47)
	{
		mlx->stepz = mlx->stepz + 1;
		ft_draw_map(mlx);
	}
	else if (key == 43)
	{
		mlx->stepz = mlx->stepz - 1;
		ft_draw_map(mlx);
	}
	else if (key == 12)
		mlx_clear_window(mlx->ptr, mlx->wnd);
	return (0);
}
