/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:29:42 by mstefani          #+#    #+#             */
/*   Updated: 2020/04/10 01:22:08 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# include <fcntl.h>
# include <mlx.h>
# include <X.h>
# include <Xlib.h>
# include "image.xpm"
# include <stdio.h>
# include <stdlib.h>
# include <zconf.h>
# include "libft.h"
# include <math.h>
# include "gnl/get_next_line.h"
# include "keys.h"
# define WX 1280
# define WY 720
# define RED 0xff0000

#define BLUE 0x0000ff
# define BACKGROUND 0x222222
# define COLOR_DEFAULT_MIN 0x008200
# define COLOR_DEFAULT_MAX 0xFFFFFF
# define INSIDE(x, y) ((x > 0 && y > 0 && x < WX && y < WY) ? 1 : 0)
# define STEP(a, b) ((a < b) ? 1 : -1)
# define STEPZ 5

typedef enum
{
	PARALLEL,
	ISO
}	t_projection;

typedef struct		s_mouse
{
	int				is_pressed;
}					t_mouse;

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				c;
	int 			x0;
	int 			y0;
	int 			z0;
	int 			c0;
}					t_dot;

typedef struct		s_camera
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	int 			offset_x;
	int 			offset_y;
}					t_camera;

typedef struct 		s_line
{
	int 			dz;
	int 			dx;
	int 			dy;
	double 			length;
}					t_line;

typedef struct		s_wnd
{
	void			*ptr;
	void			*wnd;
	void			*img;
	char			*data_addr;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
}					t_wnd;

typedef struct		s_mlx
{
	int				mx;
	int				my;
	int				stepx;
	int				stepy;
	double 			stepz;
	int				maxz;
	int 			minz;
	int				x0;
	int				y0;

	t_line			*line;
	t_wnd			*wnd;
	t_camera		*camera;
	t_dot			*dot;
	t_dot			**dots;
	t_mouse			st_mouse;
}					t_mlx;

t_wnd				*ft_init_window();
t_line				*line_init();
t_dot				*dot_init();
t_mlx				*ft_discover_map(char *filename);
t_dot				**ft_fill_map(t_mlx *mlx, char *filename);
t_camera			*camera_init();
void				ft_print_mlx(t_mlx *mlx);
void				ft_set_constants(t_mlx *mlx);
int					ft_mouse_move(int x, int y, t_mlx *mlx);
int					ft_mouse_release(int buttom, int x, int y, t_mlx *mlx);
int					ft_mouse_pressed(int buttom, int x, int y, t_mlx *mlx);
int					ft_calc_digits(char *line, t_mlx *mlx);
void 				ft_rotate(t_mlx *mlx);
void				ft_fzero(t_dot *dots, int y, int x, t_mlx *mlx);
void				ft_draw_map(t_mlx *mlx);
void				ft_draw_line(int y, int x, int step, t_mlx *mlx);
int					ft_plot_line(int x1, int y1, t_mlx *mlx);
void				ft_put_pixel(int x, int y, int color, t_mlx *mlx);
int					ft_key_win(int key, t_mlx *mlx);
void				ft_catch_order(t_mlx *mlx);
void				ft_draw(int y2, int x2, t_mlx *mlx);
void				ft_final_offset(t_mlx *mlx);
void				ft_move(int key, t_mlx *fdf);
void				ft_transform(t_mlx* mlx);
void				ft_getmaxmin(t_mlx *mlx, t_dot **dots);

#endif
