/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:02:15 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/28 15:16:12 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define MLX_GDA mlx_get_data_addr

# define WIN_X 1280
# define WIN_Y 720

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define SKY "textures/sky.xpm"

# define ESC 53
# define SET 34
# define RESET 82
# define R_LEFT 123
# define R_RIGHT 124
# define UP 126
# define DOWN 125
# define MS_UP 69
# define MS_DOWN 78
# define RS_UP 67
# define RS_DOWN 75

# define C_SEPARATION "-------------------------------"
# define C_CONTROLS " press 'I' hidden/show SETTINGS"
# define C_ESC      "|   esc  |  exit the programm |"
# define C_UP       "|   UP   |   moving forward   |"
# define C_DOWN     "|  DOWN  |   moving backward  |"
# define C_LEFT     "|  LEFT  |     turn left      |"
# define C_RIGHT    "|  RIGHT |     turn right     |"
# define C_MORE     "|   +    |    move speed up   |"
# define C_LESS     "|   -    |   move speed down  |"
# define C_STAR     "|   *    |  rotation speed up |"
# define C_SLASH    "|   /    | rotation speed down|"
# define C_RESET    "|   0    |       reset        |"

typedef struct	s_im
{
	void		*im;
	char		*imc;
	int			bpp;
	int			imlen;
	int			endi;
}				t_im;


typedef struct	s_env
{
	t_im			img;
	t_im			sky;

	double			xprime;
	void			*mlx;
	void			*win;

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

	int				set;
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
void				ft_print_set(t_env *e);

void				ft_put_pixel(t_env *e, int x, int y, int color);
void				ft_error(char *str);
void				ft_key_set(int keycode, t_env *e);

#endif
