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

#include "../fdf.h"

int			ft_close(void *param)
{
	write(1, "destroy notify : ", 21);
	(void)param;
	exit(0);
}

void		ft_catch_order(t_mlx *mlx)
{
	mlx_hook(mlx->wnd->wnd, 2, KeyPressMask, ft_key_win, mlx);
	mlx_hook(mlx->wnd->wnd, 17, KeyPressMask, ft_close, mlx);
	mlx_hook(mlx->wnd->wnd, 4, ButtonPressMask, ft_mouse_pressed, mlx);
	mlx_hook(mlx->wnd->wnd, 5, ButtonReleaseMask, ft_mouse_release, mlx);
	mlx_hook(mlx->wnd->wnd, 6, ButtonMotionMask, ft_mouse_move, mlx);
}
