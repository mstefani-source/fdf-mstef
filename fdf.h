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
# include <stdio.h>
# include <stdlib.h>
#include <zconf.h>
# include "libft.h"
# include "gnl/get_next_line.h"
# define WX 1920
# define WY 1080
# define RED 0xFF0000
# define COLOR_DEFAULT 0xF5CDA7
# define INSIDE(x, y) ((x > 0 && y > 0 && x < WX && y < WY) ? 1 : 0)
# define STEP(a, b) ((a < b) ? 1 : -1)
# define X_MIN (WX / 100) * 20
# define Y_MIN (WY / 100) * 20
# define X_MAX (WX / 100) * 90
# define Y_MAX (WY / 100) * 90

typedef struct	s_mouse
{
	int			is_pressed;
}				t_mouse;

typedef struct	s_dot
{
	int 		x;
	int 		y;
	int			z;
	int 		c;
}				t_dot;

typedef struct	s_mlx
{
	int			fd;
	void		*mlx_p;
	void		*wnd;
	int 		mx;
	int 		my;
	t_dot		dot;
	t_dot		**dots;
	t_mouse		st_mouse;
}				t_mlx;

void			ft_open_window(t_mlx *mlx, char *filename);
int				ft_mouse_move(int x, int y, t_mlx *mlx);
int				ft_mouse_release(int buttom, int x, int y, t_mlx *mlx);
int				ft_mouse_pressed(int buttom, int x, int y, t_mlx *mlx);
int				ft_plot_line(int x1, int y1, t_mlx *mlx);
int				ft_discover_map(t_mlx *mlx);
int				ft_calc_digits(char *line, t_mlx *mlx);
int             ft_fill_digits(char *line, t_mlx *mlx, int index);
void            ft_fzero(t_dot *arr, int lenx, int leny, int y);
void 			ft_draw_map(t_mlx *mlx);
void 			ft_draw_lines(int y, int x, int step, t_mlx *mlx);
#endif
