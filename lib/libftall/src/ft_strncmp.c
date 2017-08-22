/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:07:01 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 22:09:00 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 && *s2 && (unsigned char)*s1 == (unsigned char)*s2 && --n)
	{
		++s1;
		++s2;
	}
	if (!n && (!*s1 || !*s2))
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
