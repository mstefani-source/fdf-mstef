/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:46:28 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/19 14:46:34 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void    ft_fzero(t_mlx *mlx, int y)
{
	int	i;

    i = 0;
    mlx->stepz = 0;
    mlx->maxcolor = COLOR_DEFAULT_MAX;
    mlx->mincolor = COLOR_DEFAULT_MIN;
	while (mlx->mx - i)
	{
		mlx->dots[y][i].c = mlx->mincolor;
		mlx->dots[y][i].z = 0;
		mlx->dots[y][i].x = mlx->x0 + (i * mlx->stepx);
		mlx->dots[y][i].y = mlx->y0 + (y * mlx->stepy);
		i++;
	}
}