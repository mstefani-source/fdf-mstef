/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:16:13 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/05 17:16:31 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouse_move(int x, int y, t_mlx *mlx)
{
	mlx->sx = x;
	mlx->sy = y;
	if (mlx->st_mouse.is_pressed && INSIDE(x, y))
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->sx, mlx->sy, BLUE);
	return (0);
}
