/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:27:01 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/10 20:31:52 by mstefani         ###   ########.fr       */
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
