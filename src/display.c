/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:18:29 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/25 01:50:14 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_img *img, t_point ps, t_point pe, int color)
{
	int		p;
	int		xe;

	xe = pe.x;
    pe.x = pe.x - ps.x;
    pe.y = pe.y - ps.y;

    p = 2 * pe.y - pe.x;

    while (ps.x < xe)
    {
        if (p >= 0)
        {
            put_pixel(img, ps.x, ps.y, color);
            ps.y = ps.y + 1;
            p = p + 2 * pe.y - 2 * pe.x;
        }
        else
        {
            put_pixel(img, ps.x, ps.y, color);
            p = p + 2 * pe.y;
        }
        ps.x = ps.x + 1;
    }
}

void	set_point(t_point *point, int zoom)
{
	point->x *= zoom;
	point->y *= zoom;
}

void	disp_map(t_img *img, t_map *map, int zoom)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->nb_y)
	{
		x = -1;
		while (++x < map->nb_x)
		{
			set_point(&map->point[y][x], zoom);
			if ((x < (map->nb_x - 1)) && (y < (map->nb_y - 1)))
			{
				draw_line(img, map->point[y][x], map->point[y][x + 1], 0x00ffffff);
				draw_line(img, map->point[y][x], map->point[y + 1][x], 0x00ffffff);
			}
			else if (y < (map->nb_y - 1))
				draw_line(img, map->point[y][x], map->point[y + 1][x], 0x00ffffff);
			else if (x < (map->nb_x - 1))
				draw_line(img, map->point[y][x], map->point[y][x + 1], 0x00ffffff);
		}
	}
	draw_line(img, map->point[0][1], map->point[10][3], 0x00ffffff);
}
