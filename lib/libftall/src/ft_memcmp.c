/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:10:01 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 19:58:37 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ch_s1;
	unsigned char	*ch_s2;

	ch_s1 = (unsigned char *)s1;
	ch_s2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*ch_s1 == *ch_s2 && --n)
	{
		++ch_s1;
		++ch_s2;
	}
	return (*ch_s1 - *ch_s2);
}
