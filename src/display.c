/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:18:29 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/25 20:37:51 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	put_pixel(t_img *img, int x, int y, int z)
{
	char	*ptr_color;
	int		c;

	if (z > (img->z_max * 3 / 4))
		c = 0x00ffffff;
	else if (z > (img->z_max / 4))
		c = 0x0087591A;
	else
		c = 0x0016B84E;
	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	ptr_color = img->buffer + (x * (img->bpp >> 3) + y * img->line_s);
	ptr_color[0] = (c >> 0x00) & 0xFF;
	ptr_color[1] = (c >> 0x08) & 0xFF;
	ptr_color[2] = (c >> 0x10) & 0xFF;
	ptr_color[3] = (c >> 0x18) & 0xFF;
}

int		ft_abs(int x)
{
	return ((x < 0) ? (-x) : (x));
}

int		get_color(t_point p0, t_point p1, int dx, int dy)
{
	float	avx;
	float	avy;
	float	av;
	float	dxy;

	if (p0.z == p1.z)
		return (p0.z);

	avx = ft_abs(p1.x - p0.x) - dx;
	avy = ft_abs(p1.y - p0.y) - dy;
	av = sqrt(avx * avx + avy * avy);
	dxy = sqrt(dx * dx + dy * dy);
	av = av / dxy;
	if (p0.z < p1.z)
		return (av * ft_abs(p0.z - p1.z) + p0.z);
	return((1 - av) * ft_abs(p0.z - p1.z) + p1.z);
}

void	draw_line(t_img *img, t_point p0, t_point p1)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;

	dx = ft_abs(p1.x - p0.x);
	sx = p0.x < p1.x ? 1 : -1;
	dy = ft_abs(p1.y - p0.y);
	sy = p0.y < p1.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;

	while(p0.x != p1.x || p0.y != p1.y)
	{
		put_pixel(img, p0.x, p0.y, get_color(p0, p1, dx, dy));
		img->e = err;
		if (img->e > -dx)
		{
			err -= dy;
			p0.x += sx;
		}
		if (img->e < dy)
		{
			err += dx;
			p0.y += sy;
		}
	}
}

void	center_map(t_map *map, int zoom)
{
	int	x;
	int	y;
	int	center_x;
	int	center_y;

	y = -1;(void)zoom;
	center_x = (WINDOW_WIDTH -
					(map->point[map->nb_y / 2][map->nb_x / 2].x * 2)) / 2;
	center_y = (WINDOW_HEIGHT -
					(map->point[map->nb_y / 2][map->nb_x / 2].y * 2)) / 2;
	while (++y < map->nb_y)
	{
		x = -1;
		while (++x < map->nb_x)
		{
			map->point[y][x].x += center_x;
			map->point[y][x].y += center_y;
		}
	}
}

void	apply_proj(t_map *map, int zoom)
{
	int	x;
	int	y;
	int	proj_x;
	int	proj_y;

	y = -1;
	while (++y < map->nb_y)
	{
		x = -1;
		while (++x < map->nb_x)
		{
			proj_x = (map->point[y][x].x - map->point[y][x].y) * zoom / 2;
			proj_y = (map->point[y][x].x + map->point[y][x].y) * zoom / 2;
			map->point[y][x].x = proj_x;
			map->point[y][x].x += map->point[y][x].z * zoom / 30;
			map->point[y][x].y = proj_y;
			map->point[y][x].y -= map->point[y][x].z * zoom / 30;
		}
	}
}

void	disp_map(t_img *img, t_map *map, int zoom)
{
	int		x;
	int		y;

	y = -1;
	apply_proj(map, zoom);
	center_map(map, zoom);
	while (++y < map->nb_y)
	{
		x = -1;
		while (++x < map->nb_x)
		{
			if ((x < (map->nb_x - 1)) && (y < (map->nb_y - 1)))
			{
				draw_line(img, map->point[y][x], map->point[y][x + 1]);
				draw_line(img, map->point[y][x], map->point[y + 1][x]);
			}
			else if (y < (map->nb_y - 1))
				draw_line(img, map->point[y][x], map->point[y + 1][x]);
			else if (x < (map->nb_x - 1))
				draw_line(img, map->point[y][x], map->point[y][x + 1]);
		}
	}
	put_pixel(img, map->point[y - 1][x - 1].x, map->point[y - 1][x - 1].y,
						map->point[y - 1][x - 1].z);

	int		h;
	int		z;

	h = sqrt(20 * 20 + 10 * 10);
	z = ft_abs(10 - 2);
	ft_printf("h=%i, z=%i, res=%i\n",h,z, z/h);
}
