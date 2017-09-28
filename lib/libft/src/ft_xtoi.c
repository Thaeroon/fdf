/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:59:57 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/21 16:36:29 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_xtoi(char *hex)
{
	int		val;
	char	byte;

	val = 0;
	if (*hex == '0')
		if (hex[1] == 'x' || hex[1] == 'X')
			hex = hex + 2;
	while (*hex && (
					(('0' <= *hex) && (*hex <= '9')) ||
					(('a' <= *hex) && (*hex <= 'f')) ||
					(('A' <= *hex) && (*hex <= 'F'))))
	{
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}
