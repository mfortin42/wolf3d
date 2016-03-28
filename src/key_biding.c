/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 16:03:44 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/28 14:35:14 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		ft_key_biding(int keycode, t_env *e)
{
	if (keycode == SET)
		e->set = 1;
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
	if (keycode == SET)
		e->set = 0;
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
	if (e->ms_ud == 1 && e->moveSpeed < 0.2)
		e->moveSpeed += 0.002;
	if (e->ms_ud == -1 && e->moveSpeed > 0.02)
		e->moveSpeed -= 0.002;
	if (e->rs_ud == 1 && e->rotSpeed < 0.1)
		e->rotSpeed += 0.001;
	if (e->rs_ud == -1 && e->rotSpeed > 0.004)
		e->rotSpeed -= 0.001;
}

int		ft_key_core(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img.im);
	e->img.im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_do_key_action(e);
	ft_wolf_1(e);
	mlx_put_image_to_window(e->mlx, e->win, e->sky.im, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img.im, 0, 0);
	if (e->set == 1)
		ft_print_set(e);
	return (1);
}

void	ft_print_set(t_env *e)
{
	unsigned int tmp;

	tmp = 960;
	mlx_string_put(e->mlx, e->win, 0 + tmp, 0, 0xFFFFFF, C_CONTROLS);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 16, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 32, 0xFFFFFF, C_ESC);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 48, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 64, 0xFFFFFF, C_UP);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 80, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 96, 0xFFFFFF, C_DOWN);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 112, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 128, 0xFFFFFF, C_LEFT);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 144, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 160, 0xFFFFFF, C_RIGHT);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 176, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 192, 0xFFFFFF, C_MORE);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 208, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 224, 0xFFFFFF, C_LESS);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 240, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 256, 0xFFFFFF, C_STAR);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 272, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 288, 0xFFFFFF, C_SLASH);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 304, 0xFFFFFF, C_SEPARATION);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 320, 0xFFFFFF, C_RESET);
	mlx_string_put(e->mlx, e->win, 0 + tmp, 336, 0xFFFFFF, C_SEPARATION);
}
