/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:42:30 by nicolas           #+#    #+#             */
/*   Updated: 2017/09/20 16:50:28 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_fun(char *(*tf[256])(t_modif *, va_list, int*))
{
	int		i;

	i = 0;
	while (i < 256)
		tf[i++] = 0;
	tf['s'] = &conv_s;
	tf['S'] = &conv_big_s;
	tf['p'] = &conv_p;
	tf['d'] = &conv_i;
	tf['D'] = &conv_i;
	tf['i'] = &conv_i;
	tf['o'] = &conv_o;
	tf['O'] = &conv_o;
	tf['u'] = &conv_u;
	tf['U'] = &conv_u;
	tf['x'] = &conv_x;
	tf['X'] = &conv_x;
	tf['c'] = &conv_c;
	tf['C'] = &conv_big_c;
	tf['%'] = &conv_mod;
}

char	*get_fun(t_modif *info, va_list ap, int *arg_len)
{
	char	*(*tf[256])(t_modif *, va_list, int*);

	init_fun(tf);
	if (tf[(int)info->conv] == 0)
		return (NULL);
	return (tf[(int)info->conv](info, ap, arg_len));
}

void	put_arg(t_modif *modif, char **ret_str, int *ret_len, va_list ap)
{
	char	*arg;
	int		schamp;
	int		arg_len;

	arg_len = 0;
	if ((arg = get_fun(modif, ap, &arg_len)))
	{
		if ((schamp = modif->champ - arg_len) > 0)
		{
			if (modif->att & 0x2 && (modif->precision <= 0 || modif->conv == 's'
								|| modif->conv == 'S') && !(modif->att & 0x4))
				arg = ap_champ_0(&arg, schamp, modif, &arg_len);
			else
				arg = ap_champ_sp(&arg, schamp, modif, &arg_len);
		}
		*ret_len += copy_arg(ret_str, *ret_len, arg, arg_len);
	}
	else
		*ret_len += copy_arg(ret_str, *ret_len, &modif->conv, 1);
	free(arg);
}
