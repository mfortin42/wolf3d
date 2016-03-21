/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:39:47 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/21 15:33:30 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_wolf_1(t_env *e, int worldMap[24][24])
{
	e->x = 0;
	while (e->x < WIN_X)
	{
		e->cameraX = 2 * e->x / WIN_X - 1;
		e->rayPosX = e->posX;
		e->rayPosY = e->posY;
		e->rayDirX = e->dirX + e->planeX * e->cameraX;
		e->rayDirY = e->dirY + e->planeY * e->cameraY;
		e->mapX = e->rayPosX;
		e->mapY = e->rayPosY;
		e->deltaDistX = sqrt(1 + (e->rayDirY * e->rayDirY) / (e->rayDirX * e->rayDirX));
		e->deltaDistY = sqrt(1 + (e->rayDirX * e->rayDirX) / (e->rayDirY * e->rayDirY));
		e->hit = 0;
		ft_wolf_2(e);
		ft_wolf_3(e, worldMap);
		ft_wolf_4(e);
		ft_wolf_5(e);
		e->x++;
	}
}

void	ft_wolf_2(t_env *e)
{
	if (e->rayDirX < 0)
	{
		e->stepX = -1;
		e->sideDistX = (e->rayPosX - e->mapX) * e->deltaDistX;
	}
	else
	{
		e->stepX = 1;
		e->sideDistX = (e->mapX + 1.0 - e->rayPosX) * e->deltaDistX;
	}
	if (e->rayDirY < 0)
	{
		e->stepY = -1;
		e->sideDistY = (e->rayPosY - e->mapY) * e->deltaDistY;
	}
	else
	{
		e->stepY = 1;
		e->sideDistY = (e->mapY + 1.0 - e->rayPosY) * e->deltaDistY;
	}
}

void	ft_wolf_3(t_env *e, int worldMap[24][24])
{
	while (e->hit == 0)
	{
		if (e->sideDistX < e->sideDistY)
		{
			e->sideDistX += e->deltaDistX;
			e->mapX += e->stepX;
			e->side = 0;
		}
		else
		{
			e->sideDistY += e->deltaDistY;
			e->mapY += e->stepY;
			e->side = 1;
		}
		if (worldMap[e->mapX][e->mapY] > 0)
			e->hit = 1;
	}
}

void	ft_wolf_4(t_env *e)
{
	if (e->side == 0)
		e->perpWallDist = fabs((e->mapX - e->rayPosX + (1 - e->stepX) / 2) / e->rayDirX);
	else
		e->perpWallDist = fabs((e->mapY - e->rayPosY + (1 - e->stepY) / 2) / e->rayDirY);
	e->lineHeight = abs((int)(WIN_Y / e->perpWallDist));
	e->drawStart = -e->lineHeight / 2 + WIN_Y / 2;
	if (e->drawStart < 0)
		e->drawStart = 0;
	e->drawEnd = e->lineHeight / 2 + WIN_Y / 2;
	if (e->drawEnd >= WIN_Y)
		e->drawEnd = WIN_Y - 1;
//	e->lineHeight = fabs(WIN_Y / e->perpWallDist);
//	if ((e->drawStart = -e->lineHeight / 2 + WIN_Y / 2) < 0)
//		e->drawStart = 0;
//	if ((e->drawEnd = e->lineHeight / 2 + WIN_Y / 2) >= WIN_Y)
//		e->drawEnd = WIN_Y - 1;

}

void	ft_wolf_5(t_env *e)
{
	int	y;
	y = 0;
	while (y < WIN_Y)
	{
		if (y < e->drawStart)
			e->color = 0x0000FF;
		else if (y > e->drawEnd)
			e->color = 0x00FF00;
		else
			e->color = 0xFF0000;
		ft_put_pixel(e, e->x, y, e->color);
		y++;
	}
}

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int	*tmp;

	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = color;
}
