#include "../fdf.h"

void	ft_move(int key, t_mlx *mlx)
{
	if (key == ARROW_LEFT)
		mlx->camera->offset_x -= 5;
	else if (key == ARROW_RIGHT)
		mlx->camera->offset_x += 5;
	else if (key == ARROW_UP)
		mlx->camera->offset_y -= 5;
	else
		mlx->camera->offset_y += 5;
}
