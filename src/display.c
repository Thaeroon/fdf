/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:18:29 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/28 17:39:35 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_img *img, int x, int y, int z)
{
	char	*ptr_color;
	int		c;

	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->heigh)
		return ;
	if (img->c == 0)
	{
		if (z > (img->z_max * 2 / 3))
			c = 0x00ffffff;
		else if (z > (img->z_max / 3))
			c = 0x0087591A;
		else if (z == 0)
			c = 0x000880FF;
		else
			c = 0x0016B84E;
	}
	else
		c = z;
	ptr_color = img->buffer + (x * (img->bpp >> 3) + y * img->line_s);
	ptr_color[0] = (c >> 0x00) & 0xFF;
	ptr_color[1] = (c >> 0x08) & 0xFF;
	ptr_color[2] = (c >> 0x10) & 0xFF;
	ptr_color[3] = (c >> 0x18) & 0xFF;
}

void	draw_line(t_img *img, t_point p0, t_point p1, int err2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;

	if (img == NULL
		|| p0.x < 0 || p0.y < 0 || p1.x >= img->width || p1.y >= img->heigh)
		return ;
	dx = abs(p1.x - p0.x);
	sx = p0.x < p1.x ? 1 : -1;
	dy = abs(p1.y - p0.y);
	sy = p0.y < p1.y ? 1 : -1;
	err = ((dx > dy) ? dx : -dy) / 2;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		put_pixel(img, p0.x, p0.y, (img->c) ?
							get_c(p0, p1, dx, dy) : get_z(p0, p1, dx, dy));
		err2 = err;
		if (err2 > -dx)
			((err -= dy) || 1) && (p0.x += sx);
		if (err2 < dy)
			((err += dx) || 1) && (p0.y += sy);
	}
}

int		disp_map(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	ft_bzero(map->img->buffer, map->img->heigh * map->img->width *
										(map->img->bpp >> 3));
	while (++y < map->nb_y)
	{
		x = -1;
		while (++x < map->nb_x)
		{
			if ((x < (map->nb_x - 1)) && (y < (map->nb_y - 1)))
			{
				draw_line(map->img, map->point[y][x], map->point[y][x + 1], 0);
				draw_line(map->img, map->point[y][x], map->point[y + 1][x], 0);
			}
			else if (y < (map->nb_y - 1))
				draw_line(map->img, map->point[y][x], map->point[y + 1][x], 0);
			else if (x < (map->nb_x - 1))
				draw_line(map->img, map->point[y][x], map->point[y][x + 1], 0);
		}
	}
	put_pixel(map->img, map->point[y - 1][x - 1].x, map->point[y - 1][x - 1].y,
						map->point[y - 1][x - 1].z);
	return (0);
}

void	apply_proj(t_map *map)
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
			proj_x = (x - y) * map->zoom / 2;
			proj_y = (x + y) * map->zoom / 2;
			map->point[y][x].x = proj_x;
			map->point[y][x].y = proj_y;
			map->point[y][x].x += map->point[y][x].z *
									((float)map->z_height * map->zoom / P_ZOOM);
			map->point[y][x].y -= map->point[y][x].z *
									((float)map->z_height * map->zoom / P_ZOOM);
			map->point[y][x].x += map->offset_x;
			map->point[y][x].y += map->offset_y;
		}
	}
}

int		draw(t_map *map)
{
	apply_proj(map);
	disp_map(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img->ptr, 0, 0);
	return (0);
}
