/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:10:49 by nmuller           #+#    #+#             */
/*   Updated: 2016/11/07 23:12:21 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	char	*tmp;

	if (!s)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	tmp = ret;
	while (*s)
		*(ret++) = f(*(s++));
	*ret = '\0';
	return (tmp);
}
