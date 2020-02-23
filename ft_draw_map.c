/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:13:44 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/19 17:13:56 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_mlx *mlx)
{
	int ix = 0;
	int iy = 0;
	
	while (iy < mlx->my)
	{
		while (ix < mlx->mx)
		{
			ft_draw_lines(iy, ix, 0, mlx);
			ft_draw_lines(iy, ix, 1, mlx);
			ix++;
		}
		ix = 0;
		iy++;
	}
}