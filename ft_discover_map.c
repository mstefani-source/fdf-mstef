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

int		ft_cti(char a)
{
	int res;

	res = a - '0';
	return (res);
}

char	*ft_go_to_next_digit(char *line)
{
	while (!ft_isdigit(*line))
		line++;
	return (line);
}

int		ft_calc_digits(char *line, t_mlx *mlx)
{
	int res;
	int num;

	res = 0;
	num = 1;
	while (*line)
	{
		if (*line >= '0' && *line <= '9')
		{
			res *= 10;
			res = res + ft_cti(*line);
			line++;
		}
		else if (*line == ' ')
		{
			printf("%d ", res);
			line = ft_go_to_next_digit(line);
			res = 0;
			num++;
		}
	}
	mlx->mapsx = num;
	printf("%d\n", res);
	return (num);
}

int		ft_discover_map(t_mlx *mlx)
{
	char	*line;
	int		num_digits;

	mlx->mapsy = 0;
	mlx->mapsx = 0;
	num_digits = 0;
	while (get_next_line(mlx->fd, &line) != 0)
	{
		num_digits = num_digits + ft_calc_digits(line, mlx);
		mlx->mapsy++;
	}
	printf("number of digits = %d\n", num_digits);
	printf("size X = %d\n", mlx->mapsx);
	printf("size Y = %d\n", mlx->mapsy);
	return (0);
}
