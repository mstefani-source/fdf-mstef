#include "../fdf.h"

int		ft_mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->st_mouse.is_pressed && INSIDE(x, y))
	{
		ft_plot_line(x, y, mlx);
		mlx->dot->x = x;
		mlx->dot->y = y;
	}
	return (0);
}

int		ft_mouse_release(int buttom, int x, int y, t_mlx *mlx)
{
	if (buttom == 1 && INSIDE(x, y))
		mlx->st_mouse.is_pressed = 0;
	return (0);
}

int		ft_mouse_pressed(int buttom, int x, int y, t_mlx *mlx)
{
	if (buttom == 1 && INSIDE(x, y))
	{
		write(1, "button 1\n", 9);
		mlx->st_mouse.is_pressed = 1;
		mlx->dot->x = x;
		mlx->dot->y = y;
		mlx_pixel_put(mlx->wnd->ptr, mlx->wnd->wnd, x, y, mlx->dot->c);
		mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, mlx->dot->x, mlx->dot->y, RED, ft_itoa(x - WX/2 ));
		mlx_string_put(mlx->wnd->ptr, mlx->wnd->wnd, mlx->dot->x, mlx->dot->y + 10, RED, ft_itoa(y - WY/2 ));
		return (0);
	}
	if (buttom == 5 && INSIDE(x, y))
	{
		if(mlx->camera->zoom < 64)
			mlx->camera->zoom++;
	}
	if (buttom == 4 && INSIDE(x, y))
	{
		if(mlx->camera->zoom > 4)
			mlx->camera->zoom--;
	}
	ft_final_offset(mlx);
	ft_rotate(mlx);
	ft_transform(mlx);
	ft_draw_map(mlx);
	return (0);
}