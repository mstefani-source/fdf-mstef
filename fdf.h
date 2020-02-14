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
# include "libft.h"
# include "gnl/get_next_line.h"
# define WX 1024
# define WY 768
# define RED 0xFF0000
# define INSIDE(x, y) ((x > 0 && y > 0 && x < WX && y < WY) ? 1 : 0)
# define STEP(a, b) ((a < b) ? 1 : -1)

typedef struct	s_mouse
{
	int			is_pressed;
}				t_mouse;

typedef struct	s_dot
{
	int 		x;
	int 		y;
	int			z;
	int 		color;
}				t_dot;

typedef struct	s_mlx
{
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	int 		mapsx;
	int 		mapsy;
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
void			ft_fillmap(t_mlx *mlx);
int				ft_calc_digits(char *line, t_mlx *mlx);
int             ft_fill_digits(char *line, t_mlx *mlx, int index);
#endif
