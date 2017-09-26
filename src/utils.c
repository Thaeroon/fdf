/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 21:11:18 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/26 22:43:35 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int x)
{
	return ((x < 0) ? (-x) : (x));
}

int		get_c(t_point p0, t_point p1, int dx, int dy)
{
	float	avx;
	float	avy;
	float	av;
	float	dxy;

	if (p0.color == p1.color)
		return (p0.color);

	avx = ft_abs(p1.x - p0.x);
	avy = ft_abs(p1.y - p0.y);
	av = sqrt(avx * avx + avy * avy);
	dxy = sqrt(dx * dx + dy * dy);
	av = av / dxy;
	if (av > 0.5)
			return (p0.color);
	else
			return (p1.color);
}

int		get_z(t_point p0, t_point p1, int dx, int dy)
{
	float	avx;
	float	avy;
	float	av;
	float	dxy;

	if (p0.z == p1.z)
		return (p0.z);

	avx = ft_abs(p1.x - p0.x) - dx;
	avy = ft_abs(p1.y - p0.y) - dy;
	av = sqrt(avx * avx + avy * avy);
	dxy = sqrt(dx * dx + dy * dy);
	av = av / dxy;
	if (p0.z < p1.z)
		return (av * ft_abs(p0.z - p1.z) + p0.z);
	return((1 - av) * ft_abs(p0.z - p1.z) + p1.z);
}
