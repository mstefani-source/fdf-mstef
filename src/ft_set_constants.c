/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_constants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:23:45 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/09 18:25:54 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fdf.h"

void 		ft_set_constants(t_mlx *mlx)
{
	mlx->stepx = WX / (4 * mlx->mx);
	mlx->stepy = WY / (4 * mlx->my);
	mlx->x0 = 0 - (mlx->mx * mlx->stepx - mlx->stepx) / 2;
	mlx->y0 = 0 - (mlx->my * mlx->stepy - mlx->stepy) / 2;
}