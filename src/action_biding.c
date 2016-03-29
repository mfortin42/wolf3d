/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_biding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:48 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/29 13:46:33 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_do_key_action(t_env *e)
{
	if (e->res == 1)
		ft_ini_var(e);
	if (e->r_lr)
		ft_rotation(e);
	if (e->ud)
		ft_move(e);
	if (e->ms_ud == 1 && e->move_speed < 0.2)
		e->move_speed += 0.002;
	if (e->ms_ud == -1 && e->move_speed > 0.02)
		e->move_speed -= 0.002;
	if (e->rs_ud == 1 && e->rot_speed < 0.1)
		e->rot_speed += 0.001;
	if (e->rs_ud == -1 && e->rot_speed > 0.004)
		e->rot_speed -= 0.001;
}

void	ft_rotation(t_env *e)
{
	if (e->r_lr == 1)
	{
		e->old_dir_x = e->dir_x;
		e->dir_x = e->dir_x * cos(e->rot_speed) - e->dir_y * sin(e->rot_speed);
		e->dir_y = e->old_dir_x
				* sin(e->rot_speed) + e->dir_y * cos(e->rot_speed);
		e->old_plane_x = e->plane_x;
		e->plane_x = e->plane_x
					* cos(e->rot_speed) - e->plane_y * sin(e->rot_speed);
		e->plane_y = e->old_plane_x
					* sin(e->rot_speed) + e->plane_y * cos(e->rot_speed);
	}
	if (e->r_lr == -1)
	{
		e->old_dir_x = e->dir_x;
		e->dir_x = e->dir_x
				* cos(-e->rot_speed) - e->dir_y * sin(-e->rot_speed);
		e->dir_y = e->old_dir_x
				* sin(-e->rot_speed) + e->dir_y * cos(-e->rot_speed);
		e->old_plane_x = e->plane_x;
		e->plane_x = e->plane_x
					* cos(-e->rot_speed) - e->plane_y * sin(-e->rot_speed);
		e->plane_y = e->old_plane_x
					* sin(-e->rot_speed) + e->plane_y * cos(-e->rot_speed);
	}
}

void	ft_move(t_env *e)
{
	if (e->ud == 1)
	{
		if (!(e->world_map[(int)(e->pos_x + e->dir_x * e->move_speed)]
						[(int)(e->pos_y)]))
			e->pos_x += e->dir_x * e->move_speed;
		if (!(e->world_map[(int)(e->pos_x)]
						[(int)(e->pos_y + e->dir_y * e->move_speed)]))
			e->pos_y += e->dir_y * e->move_speed;
	}
	if (e->ud == -1)
	{
		if (!(e->world_map[(int)(e->pos_x - e->dir_x * e->move_speed)]
						[(int)(e->pos_y)]))
			e->pos_x -= e->dir_x * e->move_speed;
		if (!(e->world_map[(int)(e->pos_x)]
						[(int)(e->pos_y - e->dir_y * e->move_speed)]))
			e->pos_y -= e->dir_y * e->move_speed;
	}
}
