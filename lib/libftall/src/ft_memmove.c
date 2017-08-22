/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:53:51 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 18:35:22 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*ch_dest;
	const char	*ch_src;

	ch_dest = dest;
	ch_src = src;
	if (dest <= src)
		while (len--)
			*ch_dest++ = *ch_src++;
	else
	{
		ch_dest = ch_dest + len - 1;
		ch_src = ch_src + len - 1;
		while (len--)
			*ch_dest-- = *ch_src--;
	}
	return (dest);
}
