/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:41:13 by nicolas           #+#    #+#             */
/*   Updated: 2017/07/25 19:03:55 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(int argc, char **argv)
{
	int		nb_wrote;
	char	*str1 = "%*c";
	char	*str2 = "%llu";
	int	arg1 = -5;
	char arg2 = 0;

	nb_wrote = ft_printf(str1, arg1, arg2);
	printf("|<- %i\n", nb_wrote);
	printf("|<- %i", printf(str1, arg1, arg2));
	printf("\n");



	(void)argv;
	(void)arg1;
	(void)arg2;
	(void)nb_wrote;
	(void)argc;
	(void)str2;
	(void)str1;
	return (0);
}
