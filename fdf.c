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

void	ft_print_mlx (t_mlx *mlx) {
	int x = 0;
	int y = 0;

	while (y != mlx->mapsy)
	{
		while (x != mlx->mapsx)
		{
/*			printf("%d|", mlx->dots[y][x].x);
			printf("%d|", mlx->dots[y][x].y);*/
			printf("%d", mlx->dots[y][x].z);
			printf(",%d " , mlx->dots[y][x].color);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	char	*line;
	int     y = 0;

	if (argc != 2)
		return (0);
	mlx = malloc(sizeof(t_mlx));
	mlx->dot.color = RED;
	if ((mlx->fd = open(argv[1], O_RDONLY)) < 0)
	{
		write(1, "Error reading file\n", 19);
		exit(0);
	}
	ft_discover_map(mlx);									/* считывем карту, узнаём сколько строк и сколько колонок*/
	close(mlx->fd);
	ft_open_window(mlx, argv[1]);							   /* открываем снова файл и инициализируем окно*/

	mlx->dots = (t_dot **) malloc(sizeof(t_dot *) * mlx->mapsy);  /* маллочим массив интов*/
	while (get_next_line(mlx->fd, &line) != 0)                    /* заполняем массив координатами и значениями цвета */
	{
		mlx->dots[y] = (t_dot *) malloc(sizeof(t_dot) * mlx->mapsx);
        ft_fill_digits(line, mlx, y);									/* вот тут ... */
        y++;
	}
	ft_print_mlx(mlx);           										/* тупо проверим как заполнился массив */
	mlx_hook(mlx->win_ptr, 4, 0, ft_mouse_pressed, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, ft_mouse_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, ft_mouse_move, mlx);
	mlx_key_hook(mlx->win_ptr, key_win1, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
