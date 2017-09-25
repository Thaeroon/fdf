/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:52 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/25 16:23:53 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>

# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 800

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

typedef struct	s_map
{
	int		nb_x;
	int		nb_y;
	t_point	**point;
}				t_map;

typedef struct	s_img
{
	void	*ptr;
	int		height;
	int		width;
	char	*buffer;
	int		bpp;
	int		line_s;
	int		e;
	int		z_max;
}				t_img;

t_map			*get_input(const char*, t_img*);
void			put_pixel(t_img *img, int x, int y, int z);
void			disp_map(t_img *img, t_map *map, int zoom);

#endif
