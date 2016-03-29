/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:15:56 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/29 13:47:28 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_print_map(t_env *e)
{
	unsigned int i;
	unsigned int j;

	if (e->c_nbr * 5 > WIN_X / 2 || e->l_nbr * 5 > WIN_Y / 2)
		return ;
	i = 0;
	while (i < e->c_nbr)
	{
		j = 0;
		while (j < e->l_nbr)
		{
			if (e->world_map[j][i] == 1)
				ft_print_mapb(e, i + (5 * (i + 1)), j + (5 * (j + 1)),
						0x000000);
			else if ((unsigned int)e->pos_x == j && (unsigned int)e->pos_y == i)
				ft_print_mapb(e, i + (5 * (i + 1)), j + (5 * (j + 1)),
						0xFF0000);
			else
				ft_print_mapb(e, i + (5 * (i + 1)), j + (5 * (j + 1)),
						0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	ft_print_mapb(t_env *e, int x, int y, int color)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i <= 5)
	{
		j = 0;
		while (j <= 5)
		{
			ft_put_pixel(e, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
