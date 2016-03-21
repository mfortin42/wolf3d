/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:02:15 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/21 15:35:24 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIN_X 1920
# define WIN_Y 1080

#define mapWidth 24
#define mapHeight 24

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef struct	s_env
{
	void		*mlx;
	void		*win;

	void		*im;
	char		*imc;
	int			bpp;
	int			imlen;
	int			endi;

	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		oldTime;

	double			x;
	double		cameraX;
	double		cameraY;
	double		rayPosX;
	double		rayPosY;
	double		rayDirX;
	double		rayDirY;

	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;

	int			lineHeight;
	int			drawStart;
	int			drawEnd;

	int			color;
	double		moveSpeed;
	double		rotSpeed;

	int			lr;
	int			ud;

	double		oldDirX;
	double		oldPlaneX;

}				t_env;

void	ft_ini_var(t_env *e);
void	ft_wolf_1(t_env *e, int worldMap[24][24]);
void	ft_wolf_2(t_env *e);
void	ft_wolf_3(t_env *e, int worldMap[24][24]);
void	ft_wolf_4(t_env *e);
void	ft_wolf_5(t_env *e);

int		ft_key_biding(int keycode, t_env *e);
int		ft_key_release(int keycode, t_env *e);
void	ft_do_key_action(t_env *e, int worldMap[24][24]);
int		ft_key_core(t_env *e, int worldMap[24][24]);

void	ft_put_pixel(t_env *e, int x, int y, int color);

#endif
