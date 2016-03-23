/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:05:19 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/23 15:58:52 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_ini_var(t_env *e)
{
	e->posX = 9;
	e->posY = 9;
	e->dirX = -1;
	e->dirY = 0;
	e->planeX = 0;
	e->planeY = 0.66;
	e->time = 0;
	e->oldTime = 0;
	e->moveSpeed = 0.08;
	e->rotSpeed = 0.08;
}

int		main(void)
{
	t_env e;
	int i;
	int	j;
	int	**worldMap;

	i = 0;
	worldMap = (int **)malloc(sizeof(int *) * 24);
	while (i < 24)
	{
		worldMap[i] = (int *)malloc(sizeof(int) * 24);
		i++;
	}
	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			if (i == 0 || i == 23)
				worldMap[i][j] = 1;
			else if (j == 0 || j == 23)
				worldMap[i][j] = 1;
			else
				worldMap[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			printf("%d", worldMap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Wolf3D");
	e.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
	e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi);
	ft_ini_var(&e);
	ft_wolf_1(&e, worldMap);
	mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_biding, &e);
	mlx_hook(e.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &e);
	mlx_loop_hook(e.mlx, ft_key_core, &e);
	mlx_loop(e.mlx);
	return (0);
}
