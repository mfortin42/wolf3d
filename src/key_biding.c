/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 16:03:44 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/26 14:12:06 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		ft_key_biding(int keycode, t_env *e)
{
	if (keycode == RESET)
		e->res = 1;
	if (keycode == R_LEFT || keycode == R_RIGHT)
		e->r_lr = (keycode == R_LEFT ? 1 : -1);
	if (keycode == UP || keycode == DOWN)
		e->ud = (keycode == UP ? 1 : -1);
	if (keycode == MS_UP || keycode == MS_DOWN)
		e->ms_ud = (keycode == MS_UP ? 1 : -1);
	if (keycode == RS_UP || keycode == RS_DOWN)
		e->rs_ud = (keycode == RS_UP ? 1 : -1);
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == RESET)
		e->res = 0;
	if (keycode == R_LEFT || keycode == R_RIGHT)
		e->r_lr = 0;
	if (keycode == UP || keycode == DOWN)
		e->ud = 0;
	if (keycode == MS_UP || keycode == MS_DOWN)
		e->ms_ud = 0;
	if (keycode == RS_UP || keycode == RS_DOWN)
		e->rs_ud = 0;
	return (0);
}

void	ft_do_key_action(t_env *e)
{
	if (e->res == 1)
		ft_ini_var(e);
	if (e->r_lr == 1)
	{
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(e->rotSpeed) - e->dirY * sin(e->rotSpeed);
		e->dirY = e->oldDirX * sin(e->rotSpeed) + e->dirY * cos(e->rotSpeed);
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(e->rotSpeed) - e->planeY * sin(e->rotSpeed);
		e->planeY = e->oldPlaneX * sin(e->rotSpeed) + e->planeY * cos(e->rotSpeed);
	}
	if (e->r_lr == -1)
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
		if (!(e->worldMap[(int)(e->posX + e->dirX * e->moveSpeed)][(int)(e->posY)]))
			e->posX += e->dirX * e->moveSpeed;
		if (!(e->worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->moveSpeed)]))
			e->posY += e->dirY * e->moveSpeed;
	}
	if (e->ud == -1)
	{
		if (!(e->worldMap[(int)(e->posX - e->dirX * e->moveSpeed)][(int)(e->posY)]))
			e->posX -= e->dirX * e->moveSpeed;
		if (!(e->worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->moveSpeed)]))
			e->posY -= e->dirY * e->moveSpeed;
	}
	if (e->ms_ud == 1 && e->moveSpeed < 0.4)
		e->moveSpeed += 0.0025;
	if (e->ms_ud == -1 && e->moveSpeed > 0.025)
		e->moveSpeed -= 0.0025;
	if (e->rs_ud == 1 && e->rotSpeed < 0.2)
		e->rotSpeed += 0.002;
	if (e->rs_ud == -1 && e->rotSpeed > 0.004)
		e->rotSpeed -= 0.002;
}

int		ft_key_core(t_env *e)
{
	mlx_destroy_image(e->mlx, e->im);
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_do_key_action(e);
	ft_wolf_1(e);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	return (1);
}
