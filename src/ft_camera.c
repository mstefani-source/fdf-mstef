#include "../fdf.h"

void	ft_move(int key, t_mlx *mlx)
{
	if (key == LEFT)
		mlx->camera->offset_x -= 5;
	else if (key == RIGHT)
		mlx->camera->offset_x += 5;
	else if (key == UP)
		mlx->camera->offset_y -= 5;
	else
		mlx->camera->offset_y += 5;
}

void    ft_rise_or_fall(int key, t_map *map)
{
    if (key == RIZE_KEY)
        map->sz += STEPZ;
    else
        map->sz -= STEPZ;
}