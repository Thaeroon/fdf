/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:31:26 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 19:18:07 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		index;

	index = 0;
	while (index < n)
	{
		*((unsigned char*)dst + index) = *((unsigned char*)src + index);
		if (*((unsigned char*)src + index) == (unsigned char)c)
			return (dst + index + 1);
		++index;
	}
	return (NULL);
}
