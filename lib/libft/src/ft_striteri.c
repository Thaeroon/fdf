/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:07:49 by nmuller           #+#    #+#             */
/*   Updated: 2016/11/07 23:13:46 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	cpt;

	if (s && f)
	{
		cpt = 0;
		while (s[cpt])
		{
			f(cpt, s + cpt);
			++cpt;
		}
	}
}
