/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:50:43 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/27 15:33:46 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	*init(void)
{
	t_img *img;

	(!(img = (t_img*)malloc(sizeof(t_img)))) ? exit(-1) : 0;
	img->ptr = NULL;
	img->z_max = 0;
	img->c = 0;
	return (img);
}

void	center_map(t_map *map)
{
	map->offset_x += (map->img->width / 2 -
					map->point[map->nb_y / 2][map->nb_x / 2].x);
	map->offset_y += (map->img->heigh / 2 -
					map->point[map->nb_y / 2][map->nb_x / 2].y);
}

void	apply_offset(int key, t_map *map)
{
	if (key == 65361)
		map->offset_x -= map->zoom;
	if (key == 65362)
		map->offset_y -= map->zoom;
	if (key == 65363)
		map->offset_x += map->zoom;
	if (key == 65364)
		map->offset_y += map->zoom;
}

int		key_pressed(int key, void *parram)
{
	if(key == 65307)
		exit (0);
	else if (65361 <= key && key <= 65364)
		apply_offset(key, parram);
	else if (key == 32)
		center_map(parram);
	else if (key == 112)
		((t_map *)parram)->zoom += 1;
	else if (key == 109)
		((t_map *)parram)->zoom -= 1;
	else if (key == 111)
		((t_map *)parram)->z_height += 1;
	else if (key == 108)
		((t_map *)parram)->z_height -= 1;
	if ((65361 <= key && key <= 65364) || (108 <= key && key <= 112)
										|| key == 32)
		draw(parram);
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_img	*img;
	t_map	*map;

	(argc != 2) ? exit(-5) : 0;
	img = init();
	map = get_input(argv[1], img);
	map->img = img;
	get_window_size(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->img->width, map->img->heigh,
																		"fdf");
	map->img->ptr = mlx_new_image(map->mlx, map->img->width, map->img->heigh);
	map->img->buffer = mlx_get_data_addr(map->img->ptr, &(map->img->bpp),
						&(map->img->line_s), &(map->img->e));
	apply_proj(map);
	center_map(map);
	mlx_expose_hook(map->win, draw, map);
	mlx_key_hook(map->win, key_pressed, map);
	mlx_loop(map->mlx);
	destroy(map);
	return (0);
}
