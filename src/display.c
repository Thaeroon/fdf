/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:18:29 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/24 21:30:35 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		set_x(t_point *point, int x)
{
	(void)point;
	return (x);
}

int		set_y(int y)
{
	return (y);
}

void	disp_map(t_img *img, t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->nb_y)
	{
		x = -1;
		while(++x < map->nb_x)
		{
			//ft_printf("%i, %i\n", x, y);
			put_pixel(img->ptr, set_x(&(map->point[y][x]), x), set_y(y),
													map->point[y][x].color);
		}
	}
}
