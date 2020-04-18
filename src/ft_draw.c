/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:11:10 by mstefani          #+#    #+#             */
/*   Updated: 2020/03/03 22:11:12 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//double	percent(int start, int end, int current)
//{
//	double	placement;
//	double	distance;
//
//	placement = current - start;
//	distance = end - start;
//	return ((distance == 0) ? 1.0 : (placement / distance));
//}

int		rgb_to_int(int red, int green, int blue)
{
	int r;
	int g;
	int b;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	return (r << 16 | g << 8 | b);
}

double	ft_length(int x2, int y2, int x1, int y1)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int		ft_calc_color(int x2, int y2, t_mlx *mlx)
{
	int			new_color;
	double		percent;

	if (mlx->line->dz == 0)
		return (mlx->dot->c);
	percent = (mlx->line->length - ft_length(x2, y2, mlx->dot->x, mlx->dot->y)) / mlx->line->length * 100;
	if (mlx->line->dz > 0)
		percent = 100 - ((mlx->line->length - ft_length(x2, y2, mlx->dot->x, mlx->dot->y)) / mlx->line->length * 100);
	new_color = rgb_to_int(255 / 100 * percent, 153, 0);
	return (new_color);
}

void	ft_draw(int y2, int x2, t_mlx *mlx)
{
	int dx;
	int dy;
	int err;
	int e2;

	dx = ft_abs(x2 - mlx->dot->x);
	dy = ft_abs(y2 - mlx->dot->y);
	err = dx - dy;
	while ((mlx->dot->x != x2) || (mlx->dot->y != y2))
	{
		mlx->dot->c = ft_calc_color(x2, y2, mlx);
		ft_put_pixel(mlx->dot->x, mlx->dot->y, mlx->dot->c, mlx);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			mlx->dot->x += STEP(mlx->dot->x, x2);
		}
		if (e2 < dx)
		{
			err += dx;
			mlx->dot->y += STEP(mlx->dot->y, y2);
		}
	}
	ft_put_pixel(mlx->dot->x, mlx->dot->y, mlx->dot->c, mlx);
}