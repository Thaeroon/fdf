/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:06:13 by nicolas           #+#    #+#             */
/*   Updated: 2017/09/20 16:50:56 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_signed_dec(t_modif *modif, va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	if (modif->conv == 'D')
		nb = (long)nb;
	else if (modif->modif == hh)
		nb = (char)nb;
	else if (modif->modif == h)
		nb = (short int)nb;
	else if (modif->modif == l)
		nb = (long)nb;
	else if (modif->modif == ll)
		nb = (long long)nb;
	else if (modif->modif == z)
		nb = (size_t)nb;
	else if (modif->modif == none)
		nb = (int)nb;
	return (nb);
}

uintmax_t	get_unsigned_dec(t_modif *modif, va_list ap)
{
	uintmax_t	nb;

	nb = va_arg(ap, uintmax_t);
	if (modif->conv == 'U' || modif->conv == 'O')
		nb = (long)nb;
	else if (modif->modif == hh)
		nb = (unsigned char)nb;
	else if (modif->modif == h)
		nb = (unsigned short int)nb;
	else if (modif->modif == l)
		nb = (unsigned long)nb;
	else if (modif->modif == ll)
		nb = (unsigned long long)nb;
	else if (modif->modif == z)
		nb = (size_t)nb;
	else if (modif->modif == none)
		nb = (unsigned int)nb;
	return (nb);
}

char		*apply_dec_prec(t_modif *modif, char **nb_str)
{
	int		len;
	char	*tmp;
	int		i;
	int		zero;

	if (**nb_str == '0' && modif->precision == 0)
		return (ft_strdup(""));
	i = 0;
	len = ft_strlen(*nb_str);
	zero = modif->precision - len;
	if (zero <= 0)
		return (*nb_str);
	if (!(tmp = (char *)malloc(sizeof(char) * (zero + 1))))
		exit(-3);
	while (zero--)
		tmp[i++] = '0';
	tmp[i] = '\0';
	return (ft_strfjoin(&tmp, nb_str, 3));
}

char		*ap_champ_0(char **arg, int size, t_modif *modif, int *arg_len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		exit(-3);
	while (size--)
		tmp[i++] = '0';
	tmp[i] = '\0';
	*arg_len += i;
	if (modif->conv == 'i' || modif->conv == 'x' || modif->conv == 'd'
			|| modif->conv == 'D' || modif->conv == 'X' || modif->conv == 'p')
	{
		if ((*arg)[0] == '-' || (*arg)[0] == '+' || (*arg)[0] == ' ')
		{
			tmp[0] = (*arg)[0];
			(*arg)[0] = '0';
		}
		if ((*arg)[1] == 'x' || (*arg)[1] == 'X')
		{
			tmp[1] = (*arg)[1];
			(*arg)[1] = '0';
		}
	}
	return (ft_strfjoin(&tmp, arg, 3));
}

char		*ap_champ_sp(char **arg, int size, t_modif *modif, int *arg_len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		exit(-3);
	while (size--)
		tmp[i++] = ' ';
	tmp[i] = '\0';
	*arg_len += i;
	if (modif->att & 0x4)
		return (ft_strfjoin(arg, &tmp, 3));
	return (ft_strfjoin(&tmp, arg, 3));
}
