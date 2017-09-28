/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:54:32 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 22:43:51 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		j;
	size_t	n_tmp;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		if (*little == *big)
		{
			j = 0;
			n_tmp = len;
			while (little[j] == big[j] && n_tmp--)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)big);
			}
		}
		big++;
		--len;
	}
	return (NULL);
}
