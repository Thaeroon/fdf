/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:52 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/26 22:36:40 by nmuller          ###   ########.fr       */
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
# include "mlx.h"

# define P_WIN_X 800
# define P_WIN_Y 600
# define M_WIN_X 1600
# define M_WIN_Y 900
# define PREF_ZOOM 30

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

typedef struct	s_img
{
	void	*ptr;
	int		heigh;
	int		width;
	char	*buffer;
	int		bpp;
	int		line_s;
	int		e;
	int		z_max;
	int		c;
}				t_img;

typedef struct	s_map
{
	int		nb_x;
	int		nb_y;
	t_point	**point;
	int		zoom;
	int		offset_x;
	int		offset_y;
	float	z_height;
	t_img	*img;
	void	*win;
	void	*mlx;
}				t_map;

t_map			*get_input(const char*, t_img*);
void			put_pixel(t_img *img, int x, int y, int z);
int				draw(t_map *map);
int				disp_map(t_map *map);
int				get_z(t_point p0, t_point p1, int dx, int dy);
int				get_c(t_point p0, t_point p1, int dx, int dy);
int				ft_abs(int);
void			apply_proj(t_map *map);
void			center_map(t_map *map);
void			get_window_size(t_map *map);

#endif
