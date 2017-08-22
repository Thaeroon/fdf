/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:48:58 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 23:09:36 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim_len(char const *s)
{
	size_t	pre;
	size_t	len;

	pre = 0;
	len = ft_strlen(s);
	while (pre < len && (s[pre] == ' ' || s[pre] == '\n' || s[pre] == '\t'))
		++pre;
	while (len - 1 > 0 && (s[len - 1] == ' ' || s[len - 1] == '\n' ||
			s[len - 1] == '\t'))
		--len;
	if (len > pre)
		return (len - pre);
	else
		return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	i;
	size_t	trim_len;

	if (!s)
		return (NULL);
	i = 0;
	trim_len = ft_strtrim_len(s);
	if (!(ret = (char *)malloc(sizeof(char) * (trim_len + 1))))
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		++s;
	while (i < trim_len)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}
