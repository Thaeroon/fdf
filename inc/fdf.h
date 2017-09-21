/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:52 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/21 16:31:34 by nmuller          ###   ########.fr       */
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

typedef struct	s_img
{
	void	*ptr;
	int		height;
	int		width;
	char	*buffer;
	int		bpp;
	int		line_s;
	int		endian;
}				t_img;

void			get_input(const char*);

#endif
