/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:58:23 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/03 15:54:45 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_win1(int key, t_mlx *mlx)
{
	write(1, "Key pressed : ", 14);
	ft_putnbr(key);
	write(1, "\n", 1);
	if (key == 53)
		exit(0);
	if (key == 124)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->sx++, mlx->sy, 0xFF00FF);
	if (key == 126)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->sx, mlx->sy--, 0xFF00FF);
	if (key == 125)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->sx, mlx->sy++, 0xFF00FF);
	if (key == 123)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->sx--, mlx->sy, 0xFF00FF);
	return (0);
}

int		mouse_pressed(int buttom, int x, int y, t_mlx *mlx)
{
	if (buttom == 1 && INSIDE(x, y))
		mlx->st_mouse.is_pressed = 1;
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		return (0);
	mlx = malloc(sizeof(t_mlx));
	mlx->sx = WX / 2;
	mlx->sy = WY / 2;
	ft_veryfy(mlx, argv[1]);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_pressed, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, ft_mouse_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, ft_mouse_move, mlx);
	mlx_key_hook(mlx->win_ptr, key_win1, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
