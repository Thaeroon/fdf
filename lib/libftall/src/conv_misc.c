/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:51:08 by nicolas           #+#    #+#             */
/*   Updated: 2017/07/25 17:09:03 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*conv_s(t_modif *modif, va_list arg, int *arg_len)
{
	char	*str;
	char	*ret;
	int		str_len;
	int		cpt;

	if (modif->modif == l)
		return (conv_big_s(modif, arg, arg_len));
	*arg_len = (modif->precision >= 0) ? (modif->precision) : (6);
	if (!(str = (char*)va_arg(arg, char*)))
		return (ft_strdup("(null)"));
	if (modif->precision >= 0)
		str_len = modif->precision;
	else
		str_len = ft_strlen(str);
	if (!(ret = (char*)malloc(sizeof(char) * (str_len + 1))))
		return (0);
	cpt = 0;
	while (cpt < str_len && str[cpt])
	{
		ret[cpt] = str[cpt];
		++cpt;
	}
	ret[cpt] = '\0';
	*arg_len = cpt;
	return (ret);
}

char			*conv_big_c(t_modif *modif, va_list arg, int *arg_len)
{
	wchar_t		nb;
	char		*nb_str;
	char		tmp[5];

	(void)modif;
	nb = (wchar_t)va_arg(arg, wint_t);
	*arg_len = wchar_tochar(tmp, nb);
	tmp[*arg_len] = '\0';
	nb_str = ft_strdup(tmp);
	return (nb_str);
}

char			*conv_p(t_modif *modif, va_list arg, int *arg_len)
{
	modif->att |= 1;
	modif->modif = ll;
	return (conv_x(modif, arg, arg_len));
}

char			*conv_mod(t_modif *modif, va_list arg, int *arg_len)
{
	(void)modif;
	(void)arg;
	*arg_len = 1;
	return (ft_strdup("%"));
}
