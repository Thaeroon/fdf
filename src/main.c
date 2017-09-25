/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:50:43 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/25 23:37:21 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

t_img	*init(void *mlx)
{
	t_img *img;

	(!(img = (t_img*)malloc(sizeof(t_img)))) ? exit(-1) : 0;
	img->width = WINDOW_WIDTH;
	img->height = WINDOW_HEIGHT;
	img->ptr = mlx_new_image(mlx, img->width, img->height);
	img->buffer = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_s, &img->e);
	img->z_max = 0;
	img->color = 0;
	return (img);
}

int		main(int argc, char const *argv[])
{
	void	*win;
	void	*mlx;
	t_img	*img;
	t_map	*map;

	(argc != 2) ? exit(-5) : 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "test");
	img = init(mlx);
	map = get_input(argv[1], img);
	disp_map(img, map, 3);
	mlx_put_image_to_window(mlx, win, img->ptr, 0, 0);
	mlx_loop(mlx);
	return (0);
}
