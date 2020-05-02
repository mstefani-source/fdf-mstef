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

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		return (0);
	mlx = ft_discover_map(argv[1]);
	mlx->wnd = ft_init_window();
	mlx->map->dots = ft_fill_map(mlx->map, argv[1]);
	ft_catch_order(mlx);
	ft_final_offset(mlx->map, mlx->camera);
	ft_rotate(mlx->map, mlx->camera);
	ft_transform(mlx);
	ft_draw_map(mlx->wnd, mlx->map);
	ft_print_menu(mlx);
	mlx_loop(mlx->wnd->ptr);
	return (0);
}
