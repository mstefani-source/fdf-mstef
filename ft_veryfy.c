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

void	ft_veryfy(t_mlx *mlx, char *filename)
{
	if ((mlx->fd = open(filename, O_RDONLY)) < 0)
	{
		write(1, "Error reading file\n", 19);
		exit(0);
	}
	write(1, "File read OK\n", 13);
	if (!(mlx->mlx_ptr = mlx_init()))
	{
		write(1, "!! Init KO !!\n", 14);
		exit(0);
	}
	write(1, "Init      OK\n", 13);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WX, WY, "Very_Nice_FdF")))
	{
		write(1, "!! KO !!\n", 9);
		exit(1);
	}
	write(1, "Window    OK\n", 13);
}