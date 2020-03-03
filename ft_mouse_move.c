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
	if (mlx->st_mouse.is_pressed && INSIDE(x, y))
	{
		ft_plot_line(x, y, mlx);
		mlx->dot.x = x;
		mlx->dot.y = y;

	}
	mlx->dot.x = x;
	mlx->dot.y = y;

	return (0);
}
