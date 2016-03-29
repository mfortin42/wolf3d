/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:11:02 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/29 13:36:46 by mfortin          ###   ########.fr       */
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
	e->set = 1;
	e->pos_x = e->spawn_x + 0.50001;
	e->pos_y = e->spawn_y + 0.50001;
	e->dir_x = 1;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = -0.66;
	e->move_speed = 0.1;
	e->rot_speed = 0.055;
}

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int *tmp;

	if (y > WIN_Y || x > WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->img.imc[(y * e->img.imlen) + (x * (e->img.bpp / 8))];
	*tmp = color;
}

void	ft_print_set(t_env *e)
{
	unsigned int tmp;

	tmp = 960;
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
