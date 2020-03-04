/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veryfy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:19:06 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/04 13:19:12 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_find_minmaxz(t_mlx *mlx)
{
	int	x;
	int y;

	y = 0;
	mlx->minz = 0;
	mlx->maxz = 0;
	while (y < mlx->my)
	{
		x = 0;
		while (x < mlx->mx)
		{
			if (mlx->dots[y][x].z > mlx->maxz)
			{
				mlx->maxz = mlx->dots[y][x].z;
				mlx->maxcolor = mlx->dots[y][x].c;
			}
			if (mlx->dots[y][x].z < mlx->minz)
			{
				mlx->minz = mlx->dots[y][x].z;
				mlx->mincolor = mlx->dots[y][x].c;
			}
			x++;
		}
		y++;
	}
}

void	ft_open_window(t_mlx *mlx, char *filename)
{
	char	*line;
	int		y;

	y = 0;
	if ((mlx->fd = open(filename, O_RDONLY)) < 0)
		exit(0);
	write(1, "File read OK\n", 13);
	if (!(mlx->ptr = mlx_init()))
		exit(0);
	write(1, "Init      OK\n", 13);
	if (!(mlx->wnd = mlx_new_window(mlx->ptr, WX, WY, "Very_Nice_FdF")))
		exit(1);
	write(1, "Img       OK\n", 13);
	mlx->img = mlx_new_image(mlx->ptr, WX, WY);
	mlx->data_addr = mlx_get_data_addr(mlx->img, &mlx->bit_per_pixel, \
	&mlx->size_line, &mlx->endian);
	mlx->dots = (t_dot **)malloc(sizeof(t_dot *) * mlx->my);
	while (get_next_line(mlx->fd, &line) != 0)
	{
		mlx->dots[y] = (t_dot *)malloc(sizeof(t_dot) * mlx->mx);
		ft_fill_digits(line, mlx, y);
		y++;
	}
	ft_find_minmaxz(mlx);
}
