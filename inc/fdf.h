/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:52 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/24 21:15:07 by nmuller          ###   ########.fr       */
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

# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 600

typedef struct	s_point
{
	int		z;
	int		color;
}				t_point;

typedef struct	s_map
{
	int		nb_x;
	int		nb_y;
	int		z_max;
	int		z_min;
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
}				t_img;

t_map			*get_input(const char*);
void			put_pixel(t_img *img, int x, int y, unsigned int c);
void			disp_map(t_img *img, t_map *map);

#endif
