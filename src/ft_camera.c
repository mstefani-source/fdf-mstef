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

t_line		*line_init()
{
	t_line *line;

	if (!(line = (t_line *)ft_memalloc(sizeof(t_line))))
		exit(2);
	line->length = 0;
	line->dx = 0;
	line->dy = 0;
	line->dz = 0;
	return (line);
}

t_dot		*dot_init()
{
	t_dot	*dot;
	if (!(dot = (t_dot *)ft_memalloc(sizeof(t_dot))))
		exit(2);
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
	dot->z = 0;
	dot->z0 = 0;
	return (dot);
}

t_camera	*camera_init()
{
	t_camera *camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		exit(2);
	camera->zoom = 32;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->offset_x = 0;
	camera->offset_y = 0;
	camera->projection = ISO;
	return (camera);
}
