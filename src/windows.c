/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:41:34 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/26 23:11:31 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_width(t_map *map)
{
	if (map->nb_x * PREF_ZOOM < P_WIN_X)
	{
		map->zoom = P_WIN_X / map->nb_x;
		map->img->width = P_WIN_X;
	}
	else if (map->nb_x * PREF_ZOOM < M_WIN_X)
	{
		map->zoom = PREF_ZOOM;
		map->img->width = map->nb_x * PREF_ZOOM;
	}
	else
	{
		map->zoom = (M_WIN_X / map->nb_x > 0) ? (M_WIN_X / map->nb_x) : 1;
		map->img->width = M_WIN_X;
	}
}

void	get_height(t_map *map)
{
	if (map->nb_y * PREF_ZOOM < P_WIN_Y)
	{
		map->zoom = P_WIN_X / map->nb_y;
		map->img->heigh = P_WIN_X;
	}
	else if (map->nb_y * PREF_ZOOM < M_WIN_Y)
	{
		map->zoom = PREF_ZOOM;
		map->img->heigh = map->nb_y * PREF_ZOOM;
	}
	else
	{
		map->zoom = (M_WIN_Y / map->nb_y > 0) ? (M_WIN_Y / map->nb_y) : 1;
		map->img->heigh = M_WIN_Y;
	}
}

void	get_window_size(t_map *map)
{
	get_width(map);
	get_height(map);
	map->z_height = (float)map->zoom / PREF_ZOOM;
}
