/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:25:20 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/09 13:31:22 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t src_len;
	size_t dest_len;
	size_t src_len_ini;

	dest_len = 0;
	src_len_ini = 0;
	while (src[src_len_ini])
		++src_len_ini;
	while (dest[dest_len] && size)
	{
		++dest_len;
		--size;
	}
	if (size == 0)
		return (dest_len + src_len_ini);
	src_len = 0;
	while (src[src_len] && size - 1)
	{
		dest[dest_len + src_len] = src[src_len];
		--size;
		++src_len;
	}
	dest[dest_len + src_len] = '\0';
	return (dest_len + src_len_ini);
}
