/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_biding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:48 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/29 10:57:46 by mfortin          ###   ########.fr       */
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
	if (e->ms_ud == 1 && e->moveSpeed < 0.2)
		e->moveSpeed += 0.002;
	if (e->ms_ud == -1 && e->moveSpeed > 0.02)
		e->moveSpeed -= 0.002;
	if (e->rs_ud == 1 && e->rotSpeed < 0.1)
		e->rotSpeed += 0.001;
	if (e->rs_ud == -1 && e->rotSpeed > 0.004)
		e->rotSpeed -= 0.001;
}

void	ft_rotation(t_env *e)
{
	if (e->r_lr == 1)
	{
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(e->rotSpeed) - e->dirY * sin(e->rotSpeed);
		e->dirY = e->oldDirX * sin(e->rotSpeed) + e->dirY * cos(e->rotSpeed);
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(e->rotSpeed) - e->planeY * sin(e->rotSpeed);
		e->planeY = e->oldPlaneX
					* sin(e->rotSpeed) + e->planeY * cos(e->rotSpeed);
	}
	if (e->r_lr == -1)
	{
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(-e->rotSpeed) - e->dirY * sin(-e->rotSpeed);
		e->dirY = e->oldDirX * sin(-e->rotSpeed) + e->dirY * cos(-e->rotSpeed);
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX
					* cos(-e->rotSpeed) - e->planeY * sin(-e->rotSpeed);
		e->planeY = e->oldPlaneX
					* sin(-e->rotSpeed) + e->planeY * cos(-e->rotSpeed);
	}
}

void	ft_move(t_env *e)
{
	if (e->ud == 1)
	{
		if (!(e->worldMap[(int)(e->posX + e->dirX * e->moveSpeed)]
						[(int)(e->posY)]))
			e->posX += e->dirX * e->moveSpeed;
		if (!(e->worldMap[(int)(e->posX)]
						[(int)(e->posY + e->dirY * e->moveSpeed)]))
			e->posY += e->dirY * e->moveSpeed;
	}
	if (e->ud == -1)
	{
		if (!(e->worldMap[(int)(e->posX - e->dirX * e->moveSpeed)]
						[(int)(e->posY)]))
			e->posX -= e->dirX * e->moveSpeed;
		if (!(e->worldMap[(int)(e->posX)]
						[(int)(e->posY - e->dirY * e->moveSpeed)]))
			e->posY -= e->dirY * e->moveSpeed;
	}
}
