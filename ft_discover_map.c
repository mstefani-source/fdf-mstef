/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discover_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:23:45 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/09 18:25:54 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*ft_discover_map(char *filename)
{
	char	*line;
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->my = 0;
	mlx->mx = 0;
	if ((mlx->fd = open(filename, O_RDONLY)) < 0)
		exit(0);
	while (get_next_line(mlx->fd, &line) != 0)
	{
		ft_calc_digits(line, mlx);
		mlx->my++;
	}
	mlx->stepx = WX / (2 * mlx->mx);
	mlx->stepy = WY / (2 * mlx->my);
	mlx->x0 = 0 - (mlx->mx * mlx->stepx - mlx->stepx) / 2;
	mlx->y0 = 0 - (mlx->my * mlx->stepy - mlx->stepy) / 2;
	free(line);
	close(mlx->fd);
	return (mlx);
}
