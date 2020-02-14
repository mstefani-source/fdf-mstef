/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:58:23 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/03 15:54:45 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_win1(int key, t_mlx *mlx)
{
	write(1, "Key pressed : ", 14);
	ft_putnbr(key);
	write(1, "\n", 1);
	if (key == 53)
	{
		close(mlx->fd);
		free(mlx);
		exit(0);
	}
	if (key == 124)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->dot.x++, mlx->dot.y, mlx->dot.color);
	else if (key == 126)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->dot.x, mlx->dot.y--, mlx->dot.color);
	else if (key == 125)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->dot.x, mlx->dot.y++, mlx->dot.color);
	else if (key == 123)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, mlx->dot.x--, mlx->dot.y, mlx->dot.color);
	else if (key == 12)
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	*line;
	int     i = 0;
	int     num;

	if (argc != 2)
		return (0);
	mlx = malloc(sizeof(t_mlx));
	mlx->dot.color = RED;
	if ((mlx->fd = open(argv[1], O_RDONLY)) < 0)
	{
		write(1, "Error reading file\n", 19);
		exit(0);
	}
	ft_discover_map(mlx);
	close(mlx->fd);
	ft_open_window(mlx, argv[1]);

	mlx->dots = (t_dot **) malloc(sizeof(t_dot *) * mlx->mapsy);
	while (get_next_line(mlx->fd, &line) != 0)
	{
		mlx->dots[i] = (t_dot *) malloc(sizeof(t_dot) * mlx->mapsx);
        num = ft_fill_digits(line, mlx, i);
        i++;
		printf("[y] = %d [x] = %d\n", i, num);
	}
	mlx_hook(mlx->win_ptr, 4, 0, ft_mouse_pressed, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, ft_mouse_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, ft_mouse_move, mlx);
	mlx_key_hook(mlx->win_ptr, key_win1, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
