/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:50:43 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/20 18:09:33 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	put_pixel(t_img *img, int x, int y, unsigned int c)
{
	char	*ptr_color;

	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	ptr_color = img->buffer + (x * (img->bpp >> 3) + y * img->line_s);
	ptr_color[0] = (c >> 0x00) & 0xFF;
	ptr_color[1] = (c >> 0x08) & 0xFF;
	ptr_color[2] = (c >> 0x10) & 0xFF;
}

t_img	*init(void *mlx)
{
	t_img *img;

	(!(img = (t_img*)malloc(sizeof(t_img)))) ? exit(-1) : 0;
	img->width = 400;
	img->height = 300;
	img->ptr = mlx_new_image(mlx, img->width, img->height);
	img->buffer = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_s, &img->endian);
	return (img);
}

int		main(int argc, char const *argv[])
{
	void	*win;
	void	*mlx;
	t_img	*img;
	int		y;
	int		x;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");
	img = init(mlx);
	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			put_pixel(img, x, y, 0xffff0000);
		}
	}
	mlx_put_image_to_window(mlx, win, img->ptr, 10, 0);
	mlx_loop(mlx);
	(void)argc;
	(void)argv;
	return (0);
}
