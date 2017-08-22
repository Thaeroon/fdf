/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:06:46 by nicolas           #+#    #+#             */
/*   Updated: 2017/07/25 18:59:33 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_attributes(char c)
{
	if (c == '#')
		return (1);
	if (c == '0')
		return (1 << 1);
	if (c == '-')
		return (1 << 2);
	if (c == '+')
		return (1 << 3);
	if (c == ' ')
		return (1 << 4);
	return (0);
}

int			get_champ(const char **str, va_list ap)
{
	int		nb;

	nb = 0;
	while ('0' <= **str && **str <= '9')
		nb = nb * 10 + (*(*str)++ - '0');
	if (**str == '*')
	{
		nb = va_arg(ap, int);
		++(*str);
		if ('0' <= **str && **str <= '9')
		{
			nb = 0;
			while ('0' <= **str && **str <= '9')
				nb = nb * 10 + (*(*str)++ - '0');
		}
	}
	return (nb);
}

int			get_precision(const char **str, va_list ap)
{
	int		nb;

	nb = 0;
	while ('0' <= **str && **str <= '9')
		nb = nb * 10 + (*(*str)++ - '0');
	if (**str == '*')
	{
		nb = va_arg(ap, int);
		++(*str);
		if ('0' <= **str && **str <= '9')
		{
			nb = 0;
			while ('0' <= **str && **str <= '9')
				nb = nb * 10 + (*(*str)++ - '0');
		}
	}
	return (nb);
}

int			get_modif(const char **str)
{
	if (**str == 'h')
	{
		if (**str && *(*str + 1) == 'h')
		{
			(*str)++;
			return (hh);
		}
		return (h);
	}
	if (**str == 'l')
	{
		if (**str && *(*str + 1) == 'l')
		{
			(*str)++;
			return (ll);
		}
		return (l);
	}
	if (**str == 'j')
		return (j);
	if (**str == 'z')
		return (z);
	return (none);
}

const char	*get_info(const char *str, t_modif *modif, va_list ap)
{
	while (*str && (*str == '#' || *str == '0' ||
			*str == '-' || *str == '+' || *str == ' '))
		modif->att |= get_attributes(*str++);
	modif->champ = get_champ(&str, ap);
	if (*str == '.')
	{
		++str;
		modif->precision = get_precision(&str, ap);
	}
	if ((modif->modif = get_modif(&str)))
		++str;
	modif->conv = *str;
	if (modif->champ < 0)
	{
		modif->champ = -modif->champ;
		modif->att += (1 << 2);
	}
	return ((*str) ? str + 1 : str);
}
