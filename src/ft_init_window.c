/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veryfy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:19:06 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/04 13:19:12 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_wnd		*ft_init_window()
{
	t_wnd	*wnd;

	if (!(wnd = (t_wnd*)ft_memalloc(sizeof(t_wnd))))
		exit(2);
	if (!(wnd->ptr = mlx_init()))
		exit(1);
	write(1, "Init      OK\n", 13);
	if (!(wnd->wnd = mlx_new_window(wnd->ptr, WX, WY, "Very_Nice_FdF")))
		exit(1);
	write(1, "Wind      OK\n", 13);
	if (!(wnd->img = mlx_new_image(wnd->ptr, WX, WY)))
		exit(1);
	write(1, "Img       OK\n", 13);
	wnd->data_addr = mlx_get_data_addr(wnd->img, &wnd->bit_per_pixel, &wnd->size_line, &wnd->endian);
	return (wnd);
}
