/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:42:54 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 22:50:24 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = NULL;
	while (*s)
		if ((char)c == *s++)
			tmp = ((char *)s - 1);
	if ((char)c == *s)
		return ((char *)s);
	else
		return (tmp);
}
