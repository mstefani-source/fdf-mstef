/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:27:01 by mstefani          #+#    #+#             */
/*   Updated: 2020/02/10 20:31:52 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_goto_next_digit(char *line)
{
	while (!ft_isdigit(*line) && *line != '\0')
		line++;
	return (line);
}

char	*ft_goto_next_space(char *line)
{
	while (*line != ' ' && *line != '\0')
		line++;
	return (line);
}

int		ft_calc_digits(char *line, t_mlx *mlx)
{
	int res;
	int num;

	res = 0;
	num = 1;
	line = ft_goto_next_digit(line);
	while (*line)
	{
		if (*line >= '0' && *line <= '9')
		{
			res *= 10;
			res = res + (*line - '0');
			line++;
		}
		else if (*line == ' ')
		{
			line = ft_goto_next_digit(line);
			res = 0;
			num++;
		}
		else if (*line == ',')
			line = ft_goto_next_space(line);
	}
	mlx->mx = num;
	return (num);
}
