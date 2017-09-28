/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:16:20 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/20 16:51:43 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			nb_cur_max_3(char *dest, wchar_t ch)
{
	dest[0] = (ch >> 18) | 0xF0;
	dest[1] = ((ch >> 12) & 0x3F) | 0x80;
	dest[2] = ((ch >> 6) & 0x3F) | 0x80;
	dest[3] = (ch & 0x3F) | 0x80;
	return (4);
}

int			wchar_tochar(char *dest, wchar_t ch)
{
	if (ch <= 0x7F || MB_CUR_MAX == 1)
	{
		dest[0] = (char)ch;
		return (1);
	}
	if (ch <= 0x7FF || MB_CUR_MAX == 2)
	{
		dest[0] = (ch >> 6) | 0xC0;
		dest[1] = (ch & 0x3F) | 0x80;
		return (2);
	}
	if (ch <= 0xFFFF || MB_CUR_MAX == 3)
	{
		dest[0] = (ch >> 12) | 0xE0;
		dest[1] = ((ch >> 6) & 0x3F) | 0x80;
		dest[2] = (ch & 0x3F) | 0x80;
		return (3);
	}
	if (ch <= 0x10FFFF || MB_CUR_MAX == 4)
		return (nb_cur_max_3(dest, ch));
	return (0);
}

static int	get_size(wchar_t *str, int precision)
{
	int		str_len;
	int		cpt;
	char	tmp[5];

	str_len = 0;
	cpt = -1;
	if (precision != -2)
		while (str_len + wchar_tochar(tmp, str[++cpt]) <= precision)
			str_len += wchar_tochar(tmp, str[cpt]);
	else
		while (str[++cpt])
			str_len += wchar_tochar(tmp, str[cpt]);
	return (str_len);
}

char		*conv_big_s(t_modif *modif, va_list arg, int *arg_len)
{
	wchar_t	*str;
	char	*ret;
	int		str_len;
	int		cpt_str;
	int		cpt_ret;

	*arg_len = (modif->precision >= 0) ? (modif->precision) : (6);
	if (!(str = (wchar_t*)va_arg(arg, wchar_t*)))
		return (ft_strdup("(null)"));
	str_len = get_size(str, modif->precision);
	if (!(ret = (char*)malloc(sizeof(char) * (str_len + 1))))
		return (0);
	cpt_str = 0;
	cpt_ret = 0;
	while (cpt_ret < str_len && str[cpt_str])
		cpt_ret += wchar_tochar(ret + cpt_ret, str[cpt_str++]);
	ret[cpt_ret] = '\0';
	*arg_len = cpt_ret;
	return (ret);
}
