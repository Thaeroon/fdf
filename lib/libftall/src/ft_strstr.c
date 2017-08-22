/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:50:38 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/04 14:06:56 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int j;
	int bl_found;

	bl_found = 0;
	if (!*s2)
		return ((char *)s1);
	while (*s1 && !bl_found)
	{
		if (*s2 == *s1)
		{
			j = 0;
			bl_found = 1;
			while (s2[j])
			{
				if (*(s1 + j) != s2[j])
					bl_found = 0;
				j++;
			}
		}
		s1++;
	}
	return (bl_found ? (char *)s1 - 1 : 0);
}
