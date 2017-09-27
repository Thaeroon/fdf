/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:27 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/27 16:15:17 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		populate_point(t_point *point, char *data, int x, int y)
{
	point->x = x;
	point->y = y;
	point->z = ft_atoi(data);
	while (*data && (*data != ' ') && (*data != ','))
		data++;
	if (*data == ',')
	{
		point->color = ft_xtoi(++data);
		return (1);
	}
	point->color = 0x00ffffff;
	return (0);
}

void	populate_map(t_map *map, const char *file, t_img *img)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	y = -1;
	((fd = open(file, O_RDONLY)) == -1) ? exit (-1) : 0;
	while (get_next_line(fd, &line) > 0)
	{
		++y;
		x = -1;
		while (*line)
		{
			while (*line && (*line == ' '))
				line++;
			if (*line && (++x + 1))
			{
				img->c += populate_point(&map->point[y][x], line, x, y);
				img->z_max = (map->point[y][x].z > img->z_max) ?
								map->point[y][x].z : img->z_max;
			}
			while (*line && (*line != ' '))
				line++;
		}
	}
}

void	get_map_size(const char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		tmp_x;
	int		ret;

	map->nb_x = 0;
	map->nb_y = 0;
	((fd = open(file, O_RDONLY)) == -1) ? exit (-2) : 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tmp_x = 0;
		while (*line)
		{
			while (*line && (*line == ' '))
				line++;
			if (*line)
				tmp_x++;
			while (*line && (*line != ' '))
				line++;
		}
		map->nb_y++;
		map->nb_x = (map->nb_x < tmp_x) ? tmp_x : map->nb_x;
	}
	close(fd);
	(ret < 0) ? exit(-3) : 0;
}

t_map	*get_input(const char *file,t_img *img)
{
	t_map	*map;
	int		cpt;

	cpt = -1;
	(map = (t_map*)malloc(sizeof(t_map))) ? 0 : exit(-2);
	get_map_size(file, map);
	if (map->nb_x == 0)
		exit (-4);
	(map->point = (t_point**)malloc(sizeof(t_point*) * map->nb_y)) ?
																0 : exit(-2);
	while (++cpt < map->nb_y){
		(map->point[cpt] = (t_point*)malloc(sizeof(t_point) * map->nb_x)) ?
																0 : exit(-2);

	}
	populate_map(map, file, img);
	return (map);
}
