/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:24:42 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/09 13:32:16 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int src_lenth;
	unsigned int cpt;

	src_lenth = 0;
	cpt = 0;
	while (src[src_lenth])
		src_lenth++;
	while (cpt < src_lenth && cpt < n)
	{
		dest[cpt] = src[cpt];
		cpt++;
	}
	while (cpt < n)
	{
		dest[cpt] = '\0';
		cpt++;
	}
	return (dest);
}
