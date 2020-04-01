/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:30:05 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/27 21:30:13 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void 	ft_convert(t_mlx *mlx)
{
	t_dot	**array;
	int		number;
	int 	i;
	int		x;
	int 	y;

	i = 0;
	y = 0;
	number = mlx->mx * mlx->my;
	array = (t_dot**)(malloc(sizeof(t_dot*) * mlx->my));
	printf("number = %d\n", number);
	while (y < mlx->my)
	{
		x = 0;
		while (x < mlx->mx)
		{
			array[i]->x = mlx->dots[y][x].x;
			array[i]->y = mlx->dots[y][x].y;
			array[i]->z = mlx->dots[y][x].z;
			array[i]->c = mlx->dots[y][x].c;
			i++;
			x++;
		}
		y++;
	}
}