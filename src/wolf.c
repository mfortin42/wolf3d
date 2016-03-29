/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:39:47 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/29 13:45:24 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_wolf_1(t_env *e)
{
	e->x = 0;
	while (e->x < WIN_X)
	{
		e->camera_x = 2 * e->x / (double)WIN_X - 1;
		e->ray_pos_x = e->pos_x;
		e->ray_pos_y = e->pos_y;
		e->ray_dir_x = e->dir_x + e->plane_x * e->camera_x;
		e->ray_dir_y = e->dir_y + e->plane_y * e->camera_x;
		e->map_x = (int)e->ray_pos_x;
		e->map_y = (int)e->ray_pos_y;
		e->delta_dist_x = sqrt(1 + (e->ray_dir_y * e->ray_dir_y)
						/ (e->ray_dir_x * e->ray_dir_x));
		e->delta_dist_y = sqrt(1 + (e->ray_dir_x * e->ray_dir_x)
						/ (e->ray_dir_y * e->ray_dir_y));
		e->hit = 0;
		ft_wolf_2(e);
		ft_wolf_3(e);
		ft_wolf_4(e);
		ft_wolf_5(e);
		e->x++;
	}
}

void	ft_wolf_2(t_env *e)
{
	if (e->ray_dir_x < 0)
	{
		e->step_x = -1;
		e->side_dist_x = (e->ray_pos_x - e->map_x) * e->delta_dist_x;
	}
	else
	{
		e->step_x = 1;
		e->side_dist_x = (e->map_x + 1.0 - e->ray_pos_x) * e->delta_dist_x;
	}
	if (e->ray_dir_y < 0)
	{
		e->step_y = -1;
		e->side_dist_y = (e->ray_pos_y - e->map_y) * e->delta_dist_y;
	}
	else
	{
		e->step_y = 1;
		e->side_dist_y = (e->map_y + 1.0 - e->ray_pos_y) * e->delta_dist_y;
	}
}

void	ft_wolf_3(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->side_dist_x < e->side_dist_y)
		{
			e->side_dist_x += e->delta_dist_x;
			e->map_x += e->step_x;
			e->side = 0;
		}
		else
		{
			e->side_dist_y += e->delta_dist_y;
			e->map_y += e->step_y;
			e->side = 1;
		}
		if (e->world_map[e->map_x][e->map_y] > 0)
			e->hit = 1;
	}
}

void	ft_wolf_4(t_env *e)
{
	if (e->side == 0)
		e->perp_wall_dist = fabs((e->map_x - e->ray_pos_x + (1 - e->step_x) / 2)
							/ e->ray_dir_x);
	else
		e->perp_wall_dist = fabs((e->map_y - e->ray_pos_y + (1 - e->step_y) / 2)
							/ e->ray_dir_y);
	e->line_height = abs((int)(WIN_Y / e->perp_wall_dist));
	e->draw_start = -e->line_height / 2 + WIN_Y / 2;
	if (e->draw_start < 0)
		e->draw_start = 0;
	e->draw_end = e->line_height / 2 + WIN_Y / 2;
	if (e->draw_end >= WIN_Y)
		e->draw_end = WIN_Y - 1;
}

void	ft_wolf_5(t_env *e)
{
	e->y = 0;
	while (e->y < WIN_Y)
	{
		if (e->y < e->draw_start)
			e->color = 0xE077B5FE;
		else if (e->y > e->draw_end)
			e->color = 0xABD473;
		else if (e->ray_dir_x >= 0 && e->side == 0)
			e->color = 0xC41F3B;
		else if (e->ray_dir_x <= 0 && e->side == 0)
			e->color = 0xFFF569;
		else if (e->ray_dir_y <= 0 && e->side == 1)
			e->color = 0xFF7D0A;
		else
			e->color = 0x0070DE;
		ft_put_pixel(e, e->x, e->y, e->color);
		e->y++;
	}
}
