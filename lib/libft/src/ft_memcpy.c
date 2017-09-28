/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:18:04 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 19:05:46 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		index;

	index = 0;
	while (index < n)
	{
		*((unsigned char*)(dst + index)) = *((unsigned char*)(src + index));
		++index;
	}
	return (dst);
}
