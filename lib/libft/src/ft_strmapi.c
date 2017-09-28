/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:25:34 by nmuller           #+#    #+#             */
/*   Updated: 2016/11/07 23:12:16 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = f(i, s[i]);
	ret[i] = '\0';
	return (ret);
}
