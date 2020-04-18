/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:04:02 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/27 21:04:04 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_print_mlx(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y != mlx->my)
	{
		while (x != mlx->mx)
		{
			printf("%d|", mlx->dots[y][x].x);
			printf("%d|", mlx->dots[y][x].y);
			printf("%d|", mlx->dots[y][x].z);
			printf("%d ", mlx->dots[y][x].c);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}
