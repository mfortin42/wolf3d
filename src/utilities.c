/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:11:02 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/26 14:15:30 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_ini_var(t_env *e)
{
	e->posX = e->spawnX + 0.50001;
	e->posY = e->spawnY + 0.50001;
	e->dirX = 1;
	e->dirY = 0;
	e->planeX = 0;
	e->planeY = -0.66;
	e->moveSpeed = 0.1;
	e->rotSpeed = 0.07;
}

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int *tmp;

	if (y > WIN_Y || x > WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = color;
}
