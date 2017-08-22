/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:40:04 by nicolas           #+#    #+#             */
/*   Updated: 2017/08/22 07:03:19 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>

# include "libft.h"

enum
{
	none, hh, h, l, ll, j, z
};

/*
** attributes : # 0 - + ' ' bitwise
** champ : si -2 non effectif si -1 next arg
** precision : si -2 non effectif si -1 next arg
** modif : si = 0 non effectif
*/

typedef struct	s_modif
{
	int		att;
	int		champ;
	int		precision;
	int		modif;
	char	conv;
}				t_modif;

int				wchar_tochar(char *dest, wchar_t ch);
char			*ap_champ_0(char **arg, int schamp, t_modif *modif,
													int *arg_len);
char			*ap_champ_sp(char **arg, int schamp, t_modif *modif,
													int *arg_len);
char			*apply_dec_prec(t_modif *modif, char **nb_str);
char			*ft_itoa_base_unsigned(uintmax_t nb, int base, int mod);
intmax_t		get_signed_dec(t_modif *modif, va_list ap);
uintmax_t		get_unsigned_dec(t_modif *modif, va_list ap);
int				copy_arg(char **ret, int ret_len, char *arg, int arg_len);
void			put_arg(t_modif *modif, char **ret_str,
						int	*ret_len, va_list ap);
const char		*get_info(const char *str, t_modif *modif, va_list ap);
int				ft_printf(const char *format, ...);
int				copy_until_mod(const char **str, char **ret, int ret_len);
char			*ft_strcpy(char *dest, const char *src);

char			*conv_s(t_modif *modif, va_list arg, int *arg_len);
char			*conv_p(t_modif *modif, va_list arg, int *arg_len);
char			*conv_i(t_modif *modif, va_list arg, int *arg_len);
char			*conv_o(t_modif *modif, va_list arg, int *arg_len);
char			*conv_u(t_modif *modif, va_list arg, int *arg_len);
char			*conv_x(t_modif *modif, va_list arg, int *arg_len);
char			*conv_c(t_modif *modif, va_list arg, int *arg_len);
char			*conv_big_c(t_modif *modif, va_list arg, int *arg_len);
char			*conv_big_s(t_modif *modif, va_list arg, int *arg_len);
char			*conv_mod(t_modif *modif, va_list arg, int *arg_len);
int				ft_strcmp(const char *s1, const char *s2);

void			disp_info(t_modif *modif);
void			affichebin(uintmax_t n);

#endif
