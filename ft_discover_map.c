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

int		ft_discover_map(t_mlx *mlx)
{
	char	*line;
	int		num_digits;

	mlx->my = 0;
	mlx->mx = 0;
	num_digits = 0;
	while (get_next_line(mlx->fd, &line) != 0)
	{
		num_digits = num_digits + ft_calc_digits(line, mlx);
		mlx->my++;
	}
	printf("number of digits = %d\n", num_digits);
	printf("size X = %d\n", mlx->mx);
	printf("size Y = %d\n", mlx->my);

	free(line);
	return (0);
}
