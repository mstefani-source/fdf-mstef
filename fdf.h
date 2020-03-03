/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:29:42 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/03 20:29:45 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include <fcntl.h>
# include <mlx.h>
# include "image.xpm"
# include <stdio.h>
# include <stdlib.h>
# include <zconf.h>
# include "libft.h"
# include <math.h>
# include "gnl/get_next_line.h"
# define WX 1920
# define WY 1080
# define BACKGROUND	0x222222
# define COLOR_DEFAULT 0x008200
# define INSIDE(x, y) ((x > 0 && y > 0 && x < WX && y < WY) ? 1 : 0)
# define STEP(a, b) ((a < b) ? 1 : -1)

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct			s_mouse
{
	int					is_pressed;
}						t_mouse;

typedef struct			s_dot
{
	int					x;
	int					y;
	double				z;
	int					c;
}						t_dot;

typedef struct			s_mlx
{
	int					fd;
	void				*ptr;
	void				*wnd;
	void				*img;
	char				*data_addr;
	int					bit_per_pixel;
	int					size_line;
	int					endian;
	int					mx;
	int					my;
	int					stepx;
	int					stepy;
	double 				stepz;
	int					maxz;
	int 				minz;
	int					x0;
	int					y0;
	double 				len;

	t_projection		projection;
	t_dot				dot;
	t_dot				**dots;
	t_mouse				st_mouse;
}						t_mlx;

void					ft_open_window(t_mlx *mlx, char *filename);
int						ft_mouse_move(int x, int y, t_mlx *mlx);
int						ft_mouse_release(int buttom, int x, int y, t_mlx *mlx);
int						ft_mouse_pressed(int buttom, int x, int y, t_mlx *mlx);
int						ft_plot_line(int x1, int y1, t_mlx *mlx);
int						ft_calc_digits(char *line, t_mlx *mlx);
int						ft_fill_digits(char *line, t_mlx *mlx, int index);
void					ft_fzero(t_mlx *mlx, int y);
void					ft_draw_map(t_mlx *mlx);
void					ft_draw_lines(int y, int x, int step, t_mlx *mlx);
void					ft_put_pixel(int x, int y, int color, t_mlx *mlx);
int						key_win(int key, t_mlx *mlx);
void					ft_catch_order(t_mlx *mlx);
void					ft_draw(int y2, int x2, t_mlx *mlx);
t_mlx					*ft_discover_map(char *filename);
#endif
