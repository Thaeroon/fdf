/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:25:50 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 22:50:21 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if ((char)c == *s++)
			return ((char *)s - 1);
	if ((char)c == *s)
		return ((char *)s);
	else
		return (NULL);
}
