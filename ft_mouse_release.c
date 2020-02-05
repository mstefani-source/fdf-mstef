/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_release.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:18:32 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/05 17:18:46 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouse_release(int buttom, int x, int y, t_mlx *mlx)
{
	if (buttom == 1 && INSIDE(x, y))
		mlx->st_mouse.is_pressed = 0;
	return (0);
}
