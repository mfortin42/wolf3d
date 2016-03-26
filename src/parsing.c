/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:07:43 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/26 14:18:41 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_parsing(t_env *e, char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("error : failed to open.\n");
	ft_first_read(e, fd);
	if (e->c_nbr == 0)
		ft_error("error : first line is empty.\n");
	if ((close(fd)) < 0)
		ft_error("error : failed to close.\n");
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("error : failed to open.\n");
	ft_second_read(e, fd);
	if ((close(fd)) < 0)
		ft_error("error : failed to close.\n");
	if (e->c_nbr < 3 || e->l_nbr < 3)
		ft_error("error : wrong number of lines or columns.\n");
	ft_spawn_pos(e);
}

void	ft_first_read(t_env *e, int fd)
{
	char	*line;
	int		ver;

	e->l_nbr = 0;
	e->c_nbr = 0;
	while ((ver = (get_next_line(fd, &line))) > 0)
	{
		if (e->l_nbr == 0)
			e->c_nbr = ft_strlen(line);
		e->l_nbr++;
		free(line);
	}
	if (ver == -1)
		ft_error("error : didn't read a file.\n");
}

void	ft_second_read(t_env *e, int fd)
{
	char			*line;
	unsigned int	ind_l;
	unsigned int	ind_c;

	ind_l = 0;
	if ((e->worldMap = (int **)malloc(sizeof(int *) * e->l_nbr)) == NULL)
		ft_error("error : malloc failed\n");
	while ((get_next_line(fd, &line)) > 0)
	{
		ft_check_line(e, line, ind_l);
		if ((e->worldMap[ind_l] = (int *)malloc(sizeof(int) * e->c_nbr)) == NULL)
			ft_error("error : malloc failed.\n");
		ind_c = 0;
		while (ind_c < e->c_nbr)
		{
			e->worldMap[ind_l][ind_c] = line[ind_c] - '0';
			ind_c++;
		}
		free(line);
		ind_l++;
	}
}

void	ft_check_line(t_env *e, char *line, unsigned int ind_l)
{
	unsigned int i;

	i = 0;
	if (ft_strlen(line) != e->c_nbr)
		ft_error("error : wrong number of columns.\n");
	if (ind_l == 0 || ind_l == e->l_nbr - 1)
	{
		while (line[i])
		{
			if (line[i] != '1')
				ft_error("error : invalid map.\n");
			i++;
		}
	}
	if (ind_l > 0 && ind_l < e->l_nbr - 1)
	{
		if (line[0] != '1' || line[e->c_nbr - 1] != '1')
			ft_error("error : invalid map.\n");
	}
}

int		ft_spawn_pos(t_env *e)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (j < e->l_nbr - 1)
	{
		i = 0;
		while (i < e->c_nbr - 1)
		{
			if (e->worldMap[j][i] == 0)
			{
				e->spawnX = j;
				e->spawnY = i;
				return (0);
			}
			i++;
		}
		j++;
	}
	return (0);
}
