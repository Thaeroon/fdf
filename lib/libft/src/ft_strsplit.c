/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:18:11 by nicolas           #+#    #+#             */
/*   Updated: 2016/11/07 23:10:00 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		w_count(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
			++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

static int		ft_strsplit_cpy(char *dest, char const *src, char c)
{
	int cpt;

	cpt = 0;
	while (src[cpt] && src[cpt] != c)
	{
		dest[cpt] = src[cpt];
		cpt++;
	}
	dest[cpt] = '\0';
	return (cpt);
}

static int		char_count(const char *s, char c)
{
	int count;

	count = 0;
	while (*s && *s != c)
	{
		++count;
		++s;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret_tab;
	int		nb_split;

	if (!s)
		return (NULL);
	nb_split = 0;
	if (!(ret_tab = (char**)malloc(sizeof(*ret_tab) * (w_count(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
		{
			ret_tab[nb_split] = (char*)malloc(sizeof(ret_tab)
			* (char_count(s, c) + 1));
			s += ft_strsplit_cpy(ret_tab[nb_split], s, c);
			++nb_split;
		}
	}
	ret_tab[nb_split] = 0;
	return (ret_tab);
}
