/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:27:01 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/10 20:31:52 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_gnd(char *line)
{
	while (!ft_isdigit(*line) && *line != '\0')
		line++;
	return (line);
}
char	*ft_gns(char *line)
{
	while (*line != ' ' && *line != '\0')
		line++;
	return  (line);
}

int		ft_getcolor(char *line)
{
	
}

int		ft_fill_digits(char *line, t_mlx *mlx, int index)
{
	int res;
	int num;
	int i;

	i = 0;
	res = 0;
	num = 1;
	line = ft_gnd(line);
	while (*line)
	{
		if (*line >= '0' && *line <= '9')
		{
			res *= 10;
			res = res + (*line - '0');
			line++;
		}
		else if (*line == ' ')
		{
		    mlx->dots[index][i++].z = res;
			line = ft_gnd(line);
			res = 0;
			num++;
		}
		else if (*line == ',')
		{
			mlx->dots[index][i].color = ft_getcolor(line);
			line = ft_gns(line);
		}
	}
	mlx->mapsx = num;
	mlx->dots[index][i++].z = res;
	return (num);
}
