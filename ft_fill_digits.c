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

char	*ft_gonxtd(char *line)
{
	while (!ft_isdigit(*line) && *line != '\0')
		line++;
	return (line);
}
char	*ft_gns(char *line)
{
	while (*line != ' ' && *line != '\0')
		line++;
	return (line);
}

int		ft_readcolor(char *line)
{
	char hexc[6];
	int i = 0;
	int color = 0;

	line = line + 3;
	while (*line != ' ' && *line != '\0')
	{
		hexc[i++] = *line;
		line++;
	}
	hexc[i] = '\0';
	color = ft_atoi_base(hexc, 16);
	return (color);
}

int		ft_fill_digits(char *line, t_mlx *mlx, int y)
{
	int res;
	int x;

	x = 0;
	res = 0;
	line = ft_gonxtd(line);
	while (*line)
	{
		mlx->dots[y][x].x = x * 10;
		mlx->dots[y][x].y = y * 10;
		if (*line >= '0' && *line <= '9')
		{
			res *= 10;
			res = res + (*line - '0');
			line++;
		}
		else if (*line == ' ')
		{
		    mlx->dots[y][x].z = res;
			line = ft_gonxtd(line);
			res = 0;
			x++;
		}
		else if (*line == ',')
		{
			mlx->dots[y][x].color = ft_readcolor(line);
			line = ft_gns(line);
		}
	}
	return (0);
}
