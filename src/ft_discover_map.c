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

#include "../fdf.h"

void	ft_getmaxmin(t_mlx *mlx, t_dot **dots)
{
	int x;
	int y;

	y = 0;
	mlx->minz = 0;
	mlx->maxz = 0;
	while (y < mlx->my)
	{
		x = 0;
		while (x < mlx->mx)
		{
		if (dots[y][x].z > mlx->maxz)
			mlx->maxz = dots[y][x].z;
		if (dots[y][x].z < mlx->minz)
			mlx->minz = dots[y][x].z;
		x++;
		}
	y++;
	}
}

t_mlx		*ft_discover_map(char *filename)
{
	int 	fd;
	char	*line;
	t_mlx	*mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		exit (2);
	mlx->my = 0;
	mlx->mx = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		exit(1);
	while (get_next_line(fd, &line) != 0)
	{
		ft_calc_digits(line, mlx);
		mlx->my++;
	}
	free(line);
	close(fd);
	ft_set_constants(mlx);
	return (mlx);
}
