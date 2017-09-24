/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:27 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/24 21:29:12 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	disp_map_char(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->nb_y)
	{
		x = -1;
		while(++x < map->nb_x)
		{
			ft_printf("%i,%i ", map->point[y][x].z, map->point[y][x].color);
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
		point->color = ft_xtoi("0xffffff");
}

int		populate_map(t_map *map, const char *file)
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
				populate_point(&map->point[y][++x], line);
			while (*line && (*line != ' '))
				line++;
		}
	}
	return (0);
}

void	get_map_size(const char *file, t_map *map)
{
	int		fd;
	char	*line;

	map->nb_x = 0;
	map->nb_y = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	 	exit (-2);
	if (get_next_line(fd, &line) > 0)
	{
		while (*line)
		{
			while (*line && (*line == ' '))
				line++;
			if (*line)
				map->nb_x++;
			while (*line && (*line != ' '))
				line++;
		}
		map->nb_y++;
		while (get_next_line(fd, &line) > 0)
			map->nb_y++;
	}
	close(fd);
}

t_map	*get_input(const char *file)
{
	t_map	*map;
	int		cpt;

	cpt = -1;
	(map = (t_map*)malloc(sizeof(t_map))) ? 0 : exit(-2);
	get_map_size(file, map);
	(map->point = (t_point**)malloc(sizeof(t_point*) * map->nb_y)) ? 0 : exit(-2);
	while (++cpt < map->nb_x)
		(map->point[cpt] = (t_point*)malloc(sizeof(t_point) * map->nb_x)) ? 0 : exit(-2);
	ft_printf("%i %i\n", map->nb_x, map->nb_y);
	populate_map(map, file);
	disp_map_char(map);
	return (map);
}
