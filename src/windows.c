/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:41:34 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/27 14:00:19 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_width(t_map *map)
{
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
}

void	get_zoom(t_map *map)
{
	int		min_size;

	min_size = (map->nb_y < map->nb_x) ? map->nb_x : map->nb_y;
	if (min_size * P_ZOOM < P_WIN_Y)
		map->zoom = P_WIN_X / map->nb_y;
	else if (min_size * P_ZOOM < M_WIN_Y)
		map->zoom = P_ZOOM;
	else
		map->zoom = (M_WIN_Y / map->nb_y > 1) ? (M_WIN_Y / map->nb_y) : 2;
}

void	get_window_size(t_map *map)
{
	get_width(map);
	get_zoom(map);
	map->z_height = 1;
}
