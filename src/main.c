/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:05:19 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/28 15:08:34 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		main(int argc, char **argv)
{
	t_env			e;
	int	x;
	int	y;

	x = WIN_X;
	y = WIN_Y / 2;
	if (argc == 2)
	{
		ft_parsing(&e, argv[1]);
		ft_ini_var(&e);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Wolf3D");
		e.img.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
		e.img.imc = MLX_GDA(e.img.im, &e.img.bpp, &e.img.imlen, &e.img.endi);
		e.sky.im = mlx_xpm_file_to_image(e.mlx, SKY, &x, &y);
		e.sky.imc = MLX_GDA(e.sky.im, &e.sky.bpp, &e.sky.imlen, &e.sky.endi);
		ft_wolf_1(&e);
		mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_biding, &e);
		mlx_hook(e.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &e);
		mlx_loop_hook(e.mlx, ft_key_core, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error("error : wrong number of arguments.\n");
	return (0);
}
