/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 21:11:18 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/28 17:17:56 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_c(t_point p0, t_point p1, int dx, int dy)
{
	float	avx;
	float	avy;
	float	av;
	float	dxy;

	if (p0.color == p1.color)
		return (p0.color);
	avx = abs(p1.x - p0.x);
	avy = abs(p1.y - p0.y);
	av = sqrt(avx * avx + avy * avy);
	dxy = sqrt(dx * dx + dy * dy);
	av = av / dxy;
	if (av > 0.5)
		return (p0.color);
	else
		return (p1.color);
}

int		get_z(t_point p0, t_point p1, int dx, int dy)
{
	float	avx;
	float	avy;
	float	av;
	float	dxy;

	if (p0.z == p1.z)
		return (p0.z);
	avx = abs(p1.x - p0.x) - dx;
	avy = abs(p1.y - p0.y) - dy;
	av = sqrt(avx * avx + avy * avy);
	dxy = sqrt(dx * dx + dy * dy);
	av = av / dxy;
	if (p0.z < p1.z)
		return (av * abs(p0.z - p1.z) + p0.z);
	return ((1 - av) * abs(p0.z - p1.z) + p1.z);
}

void	get_window_size(t_map *map)
{
	int		min_size;

	if (map->nb_x * P_ZOOM < P_WIN_X)
		map->img->width = P_WIN_X;
	else if (map->nb_x * P_ZOOM < M_WIN_X)
		map->img->width = map->nb_x * P_ZOOM;
	else
		map->img->width = M_WIN_X;
	if (map->nb_y * P_ZOOM < P_WIN_Y)
		map->img->heigh = P_WIN_X;
	else if (map->nb_y * P_ZOOM < M_WIN_Y)
		map->img->heigh = map->nb_y * P_ZOOM;
	else
		map->img->heigh = M_WIN_Y;
	min_size = (map->nb_y < map->nb_x) ? map->nb_x : map->nb_y;
	if (min_size * P_ZOOM < P_WIN_Y)
		map->zoom = P_WIN_X / map->nb_y;
	else if (min_size * P_ZOOM < M_WIN_Y)
		map->zoom = P_ZOOM;
	else
		map->zoom = (M_WIN_Y / map->nb_y > 1) ? (M_WIN_Y / map->nb_y) : 2;
	map->z_height = 1;
}

void	destroy(t_map *map)
{
	int		y;

	y = -1;
	free(map->img);
	while (++y < map->nb_y)
		free(map->point[y]);
	free(map);
}
