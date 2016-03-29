/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 16:03:44 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/29 10:53:41 by mfortin          ###   ########.fr       */
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

int		ft_key_core(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img.im);
	e->img.im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_do_key_action(e);
	ft_wolf_1(e);
	mlx_put_image_to_window(e->mlx, e->win, e->sky.im, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, e->img.im, 0, 0);
	mlx_string_put(e->mlx, e->win, 960, 0, 0xFFFFFF, C_CONTROLS);
	if (e->set == 1)
		ft_print_set(e);
	return (1);
}
