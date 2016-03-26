/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:02:15 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/26 14:12:50 by mfortin          ###   ########.fr       */
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

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define ESC 53
# define RESET 82
# define R_LEFT 123
# define R_RIGHT 124
# define UP 126
# define DOWN 125
# define MS_UP 69
# define MS_DOWN 78
# define RS_UP 67
# define RS_DOWN 75

typedef struct	s_env
{
	double			xprime;
	void			*mlx;
	void			*win;

	void			*im;
	char			*imc;
	int				bpp;
	int				imlen;
	int				endi;

	unsigned int	c_nbr;
	unsigned int	l_nbr;
	int				**worldMap;

	unsigned int	spawnX;
	unsigned int	spawnY;

	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;

	int				x;
	int				y;
	double			cameraX;
	double			rayPosX;
	double			rayPosY;
	double			rayDirX;
	double			rayDirY;

	int				mapX;
	int				mapY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;

	int				lineHeight;
	int				drawStart;
	int				drawEnd;

	int				color;
	double			moveSpeed;
	double			rotSpeed;

	int				res;
	int				r_lr;
	int				ud;
	int				ms_ud;
	int				rs_ud;

	double			oldDirX;
	double			oldPlaneX;

}					t_env;

void				ft_parsing(t_env *e, char *file);
void				ft_first_read(t_env *e, int fd);
void				ft_second_read(t_env *e, int fd);
void				ft_check_line(t_env *e, char *line, unsigned int i);
int					ft_spawn_pos(t_env *e);

void				ft_ini_var(t_env *e);
void				ft_wolf_1(t_env *e);
void				ft_wolf_2(t_env *e);
void				ft_wolf_3(t_env *e);
void				ft_wolf_4(t_env *e);
void				ft_wolf_5(t_env *e);

int					ft_key_biding(int keycode, t_env *e);
int					ft_key_release(int keycode, t_env *e);
void				ft_do_key_action(t_env *e);
int					ft_key_core(t_env *e);

void				ft_put_pixel(t_env *e, int x, int y, int color);
void				ft_error(char *str);

#endif
