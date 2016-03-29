/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:24:50 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/29 13:48:37 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

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

# define SKY "src/sky.xpm"

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

typedef struct		s_im
{
	void			*im;
	char			*imc;
	int				bpp;
	int				imlen;
	int				endi;
}					t_im;

typedef struct		s_env
{
	t_im			img;
	t_im			sky;

	void			*mlx;
	void			*win;

	unsigned int	c_nbr;
	unsigned int	l_nbr;
	int				**world_map;

	unsigned int	spawn_x;
	unsigned int	spawn_y;

	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;

	int				x;
	int				y;
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;

	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;

	int				line_height;
	int				draw_start;
	int				draw_end;

	int				color;
	double			move_speed;
	double			rot_speed;

	int				set;
	int				res;
	int				r_lr;
	int				ud;
	int				ms_ud;
	int				rs_ud;

	double			old_dir_x;
	double			old_plane_x;

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
void				ft_rotation(t_env *e);
void				ft_move(t_env *e);
int					ft_key_core(t_env *e);

void				ft_print_set(t_env *e);
void				ft_put_pixel(t_env *e, int x, int y, int color);
void				ft_error(char *str);
void				ft_key_set(int keycode, t_env *e);

void				ft_print_map(t_env *e);
void				ft_print_mapb(t_env *e, int x, int y, int color);

#endif
