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
# include <stdlib.h>
# include "libft.h"
# define WX 640
# define WY 480
# define BLUE 0x00FFFF
# define INSIDE(x, y) ((x > 0 && y > 0 && x < WX && y < WY) ? 1 : 0)

typedef struct	s_mouse
{
	double		prev_x;
	double		prev_y;
	double		x;
	double		y;
	double		x_ratio;
	double		y_ratio;
	int			freeze;
	int			is_pressed;
}				t_mouse;

typedef struct	s_mlx
{
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	int			sx;
	int			sy;
	t_mouse		st_mouse;
}				t_mlx;

void			ft_veryfy(t_mlx *mlx, char *filename);
int				ft_mouse_move(int x, int y, t_mlx *mlx);
int				ft_mouse_release(int buttom, int x, int y, t_mlx *mlx);
#endif
