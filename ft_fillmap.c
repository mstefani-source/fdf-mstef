/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:32:15 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/10 20:32:20 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_fillmap(t_mlx *mlx)
{
	int res;
	char *line;

	res = 0;
	mlx->map = (int **) malloc(sizeof(int *) * mlx->mapsy);
	while (res < mlx->mapsy)
	{
		mlx->map[res] = (int *) (sizeof(int) * mlx->mapsx);
		while (get_next_line(mlx->fd, &line) != 0)
		{
			ft_calc_digits(line, mlx);
			mlx->mapsy++;
		}
		res++;
	}
}
