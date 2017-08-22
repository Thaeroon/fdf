/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:11:05 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/24 14:25:26 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	to_free = 00	|| 01	|| 10	|| 11
** 			  none	  *s1	  *s2	  both
*/

char	*ft_strfjoin(char **s1, char **s2, int to_free)
{
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = ft_strjoin(*s1, *s2);
	if (to_free & 0x1)
		free(*s1);
	if (to_free & 0x2)
		free(*s2);
	return (ret);
}
