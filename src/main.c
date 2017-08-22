/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:50:43 by nmuller           #+#    #+#             */
/*   Updated: 2017/08/22 07:27:48 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int		main(int argc, char const *argv[])
{
	void	*win;
	void	*mlx;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");
	mlx_loop(mlx);
	(void) argc;
	(void) argv;
 	return (0);
}
