/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:30:23 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:10:49 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int n)
{
	int				len;
	char			*res;
	int				dig;

	dig = n;
	len = ft_leni(dig);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	res[len] = '\0';
	len--;
	if (n < 0)
	{
		res[0] = '-';
		dig = -dig;
	}
	if (n / 1 == 0)
		res[0] = '0';
	while (dig != 0)
	{
		res[len] = (dig % 10) + '0';
		dig = dig / 10;
		len--;
	}
	return (res);
}
