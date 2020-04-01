/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:56:33 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/25 16:56:36 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * (int)cos(0.523599);
	*y = -z + (previous_x + previous_y) * (int)sin(0.523599);
}

t_dot ft_transform(t_dot dot, t_mlx* mlx)
{
	if (mlx->projection == ISO)
		iso(&dot.x, &dot.y, dot.z);
	return (dot);
}
