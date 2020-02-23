/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:46:28 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/19 14:46:34 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_fzero(t_dot *dots, int lenx, int leny, int y)
{
	int		i;
	int		stepx;
	int		stepy;

    i = 0;
    stepx = (X_MAX - X_MIN) / lenx;
	stepy = (Y_MAX - Y_MIN) / leny;
	while (lenx - i)
	{
		dots[i].c = COLOR_DEFAULT;
		dots[i].z = 0;
		dots[i].x = X_MIN + (i * stepx);
		dots[i].y = Y_MIN + (y * stepy);
		i++;
	}

}