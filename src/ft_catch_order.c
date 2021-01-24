/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:00:12 by mstefani          #+#    #+#             */
/*   Updated: 2020/07/25 20:19:42 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_close(void *param)
{
	write(1, "destroy notify : \n", 18);
	(void)param;
	exit(0);
}

void		ft_catch_order(t_mlx *mlx)
{
	mlx_hook(mlx->wnd->wnd, 2, (1L << 0), ft_key_win, mlx);
	mlx_hook(mlx->wnd->wnd, 17, (1Lu << 17), ft_close, mlx);
	mlx_hook(mlx->wnd->wnd, 4, (1L << 2), ft_mouse_pressed, mlx);
	mlx_hook(mlx->wnd->wnd, 5, (1 << 3), ft_mouse_release, mlx);
	mlx_hook(mlx->wnd->wnd, 6, (1 << 7), ft_mouse_move, mlx);


	/*
	mlx_hook(mlx->wnd->wnd, 2, (1Lu << 2), ft_key_win, mlx);
	mlx_hook(mlx->wnd->wnd, 17, (1Lu << 17u), ft_close, mlx);
	mlx_hook(mlx->wnd->wnd, 4, (1Lu << 8), ft_mouse_pressed, mlx);
	mlx_hook(mlx->wnd->wnd, 5, (1 << 8), ft_mouse_release, mlx);
	mlx_hook(mlx->wnd->wnd, 6, (1 << 8), ft_mouse_move, mlx);
	*/
}
