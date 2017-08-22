/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:47:59 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 18:35:36 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ch_src;
	unsigned char			ch_c;
	size_t					index;

	index = 0;
	ch_c = (unsigned char)c;
	ch_src = s;
	while (index < n)
		if (ch_c == ch_src[index++])
			return ((void *)ch_src + index - 1);
	return (NULL);
}
