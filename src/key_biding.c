/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 16:03:44 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/21 15:35:51 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		ft_key_biding(int keycode, t_env *e)
{
	if (keycode == LEFT || keycode == RIGHT)
		e->lr = (keycode == LEFT ? 1 : -1);
	if (keycode == UP || keycode == DOWN)
		e->ud = (keycode == UP ? 1 : -1);
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == LEFT || keycode == RIGHT)
		e->lr = 0;
	if (keycode == UP || keycode == DOWN)
		e->ud = 0;
	return (0);
}

void	ft_do_key_action(t_env *e, int worldMap[24][24])
{
	if (e->lr == 1)
	{
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(e->rotSpeed) - e->dirY * sin(e->rotSpeed);
		e->dirY = e->oldDirX * sin(e->rotSpeed) + e->dirY * cos(e->rotSpeed);
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(e->rotSpeed) - e->planeY * sin(e->rotSpeed);
		e->planeY = e->oldPlaneX * sin(e->rotSpeed) + e->planeY * cos(e->rotSpeed);
	}
	if (e->lr == -1)
	{
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(-e->rotSpeed) - e->dirY * sin(-e->rotSpeed);
		e->dirY = e->oldDirX * sin(-e->rotSpeed) + e->dirY * cos(-e->rotSpeed);
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(-e->rotSpeed) - e->planeY * sin(-e->rotSpeed);
		e->planeY = e->oldPlaneX * sin(-e->rotSpeed) + e->planeY * cos(-e->rotSpeed);
	}
	if (e->ud == 1)
	{
		if (worldMap[(int)(e->posX + e->dirX * e->moveSpeed)][(int)(e->posY)] == 0)
			e->posX += e->dirX * e->moveSpeed;
		if (worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->moveSpeed)] == 0)
			e->posY += e->dirY * e->moveSpeed;
	}
	if (e->ud == -1)
	{
		if (worldMap[(int)(e->posX - e->dirX * e->moveSpeed)][(int)(e->posY)] == 0)
			e->posX -= e->dirX * e->moveSpeed;
		if (worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->moveSpeed)] == 0)
			e->posY -= e->dirY * e->moveSpeed;
	}
}

int		ft_key_core(t_env *e, int worldMap[24][24])
{
	mlx_destroy_image(e->mlx, e->im);
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_do_key_action(e, worldMap);
	ft_wolf_1(e, worldMap);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	return (1);
}
