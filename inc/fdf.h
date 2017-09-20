/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 06:24:52 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/20 17:46:52 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>

# include <math.h>
# include <stdlib.h>

typedef struct	s_point
{
	int		x;
	int		y;
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

#endif
