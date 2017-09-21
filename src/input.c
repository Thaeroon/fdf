/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:27 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/21 16:43:09 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	disp_map(t_point **map, int nb_x, int nb_y)
{
	int		x;
	int		y;

	y = -1;
	while (++y < nb_y)
	{
		x = -1;
		while(++x < nb_x)
		{
			ft_printf("%i,%i ", map[y][x].z, map[y][x].color);
		}
		ft_printf("\n");
	}
}

void	populate_point(t_point *point, char *data)
{
	point->z = ft_atoi(data);
	while (*data && (*data != ' ') && (*data != ','))
		data++;
	if (*data == ',')
		point->color = ft_xtoi(++data);
	else
		point->color = 0;
}

int		populate_map(t_point **map, const char *file)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	y = -1;
	if ((fd = open(file, O_RDONLY)) == -1)
	 	exit (-2);
	while (get_next_line(fd, &line) > 0)
	{
		++y;
		x = -1;
		while (*line)
		{
			while (*line && (*line == ' '))
				line++;
			if (*line)
				populate_point(&(map[y][++x]), line);
			while (*line && (*line != ' '))
				line++;
		}
	}
	return (0);
}

void	get_map_size(const char *file, int *nb_x, int *nb_y)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
	 	exit (-2);
	if (get_next_line(fd, &line) > 0)
	{
		while (*line)
		{
			while (*line && (*line == ' '))
				line++;
			if (*line)
				(*nb_x)++;
			while (*line && (*line != ' '))
				line++;
		}
		++(*nb_y);
		while (get_next_line(fd, &line) > 0)
			++(*nb_y);
	}
	close(fd);
}

void	get_input(const char *file)
{
	int		nb_x;
	int		nb_y;
	t_point	**map;
	int		cpt;

	nb_x = 0;
	nb_y = 0;
	cpt = -1;
	get_map_size(file, &nb_x, &nb_y);
	(map = (t_point**)malloc(sizeof(t_point*) * nb_y)) ? 0 : exit(-2);
	while (++cpt < nb_x)
		(map[cpt] = (t_point*)malloc(sizeof(t_point) * nb_x)) ? 0 : exit(-2);
	ft_printf("%i %i\n", nb_x, nb_y);
	populate_map(map, file);
	disp_map(map, nb_x, nb_y);
}
