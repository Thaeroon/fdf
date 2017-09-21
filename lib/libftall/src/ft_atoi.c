/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:12:53 by nicolas           #+#    #+#             */
/*   Updated: 2017/09/21 14:43:24 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int nb;
	int str_start;
	int len;

	nb = 0;
	len = 0;
	if (!nptr)
		return (0);
	while (nptr[len] == ' ' || nptr[len] == '\t' || nptr[len] == '\v'
		|| nptr[len] == '\f' || nptr[len] == '\r' || nptr[len] == '\n')
		len++;
	str_start = len;
	if (nptr[len] == '-' || nptr[len] == '+')
		len++;
	while ('0' <= nptr[len] && nptr[len] <= '9')
	{
		nb = nb * 10 + (nptr[len] - '0');
		len++;
	}
	if (nptr[str_start] == '-')
		nb *= -1;
	return (nb);
}
