/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:00:12 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/27 20:03:26 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_close(void *param)
{
	(void)param;
	exit(0);
}

void		ft_catch_order(t_mlx *mlx)
{
	mlx_hook(mlx->wnd, 2, 0, key_win, mlx);
	mlx_hook(mlx->wnd, 17, 0, ft_close, mlx);
	mlx_hook(mlx->wnd, 4, 0, ft_mouse_pressed, mlx);
	mlx_hook(mlx->wnd, 5, 0, ft_mouse_release, mlx);
	mlx_hook(mlx->wnd, 6, 0, ft_mouse_move, mlx);
}
