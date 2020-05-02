#include "../fdf.h"

double	ft_percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

double	ft_length(int x2, int y2, int x1, int y1)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

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

int				calculate_color(t_map *map, t_dot point)
{
	int			color;
	int			diff;
	double		diff_pcnt;

	if (abs(point.z - map->min_z) <= abs(point.z - map->mid_z))
	{
		diff = map->mid_z - map->min_z;
		if (diff != 0)
			diff_pcnt = (point.z - map->min_z) / (double)diff;
		else
			diff_pcnt = 0.0;
		color = get_line_color(map->color_min, map->color_mid, diff_pcnt);
		return (color);
	}
	else
	{
		diff = map->max_z - map->mid_z;
		if (diff != 0)
			diff_pcnt = (point.z - map->mid_z) / (double)diff;
		else
			diff_pcnt = 0.0;
		color = get_line_color(map->color_mid, map->color_max, diff_pcnt);
		return (color);
	}
}

//int		ft_calc_pixelcolor(int x2, int y2, t_mlx *mlx)
//{
//	int			new_color;
//	double		percent;
//
//	if (mlx->line->dz == 0)
//		return (mlx->line->start_color);
//	if (mlx->line->dz < 0)
//		percent = 100 - ((mlx->line->length - ft_length(x2, y2, mlx->dot->x, mlx->dot->y)) / mlx->line->length * 100);
//	else
//		percent = (mlx->line->length - ft_length(x2, y2, mlx->dot->x, mlx->dot->y)) / mlx->line->length * 100;
//	new_color = rgb_to_int(255 / 100 * percent, 153, 0);
//	return (new_color);
//}

/*
int				calculate_color(t_map *map, t_dot point)
{
	int			color;
	int			diff;
	double		diff_pcnt;


	if (ft_abs(point.z - map->min_z) <= ft_abs(point.z - ((map->max_z + map->min_z) / 2)))
	{
		diff = map->mid_z - map->min_z;
		if (diff != 0)
			diff_pcnt = (point.z - map->min_z) / (double)diff;
		else
			diff_pcnt = 0.0;
		color = get_line_color(fdf->color_min, fdf->color_mid, diff_pcnt);
		return (color);
	}
	else
	{
		diff = map->max_z - map->mid_z;
		if (diff != 0)
			diff_pcnt = (point.z - map->mid_z) / (double)diff;
		else
			diff_pcnt = 0.0;
		color = get_line_color(fdf->color_mid, fdf->color_max, diff_pcnt);
		return (color);
	}
}*/