/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_pressed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:26:16 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/05 17:40:51 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouse_pressed(int buttom, int x, int y, t_mlx *mlx)
{
	if (buttom == 1 && INSIDE(x, y))
	{
		mlx->st_mouse.is_pressed = 1;
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->dot.x, mlx->dot.y, mlx->dot.color);
	}
	return (0);
}
