/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:55:14 by nmuller           #+#    #+#             */
/*   Updated: 2017/09/28 01:43:57 by nmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		ft_strtestjoin(char *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;
	size_t	index;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (0);
	index = 0;
	while (index < len_s1)
		ret[index++] = *s1++;
	while (index - len_s1 < len_s2)
		ret[index++] = *s2++;
	ret[index] = '\0';
	free(s1);
	s1 = ret;
	return (1);
}

int		read_buff(char *buff, char **line)
{
	char	*endl;

	if ((endl = ft_strchr(buff, '\n')))
	{
		*endl = '\0';
		*line = ft_strdup(buff);
		buff = ft_strcpy(buff, endl + 1);
		return (0);
	}
	else
	{
		*line = ft_strdup(buff);
		ft_bzero(buff, BUFF_SIZE);
		return (1);
	}
}

int		read_file(const int fd, char **line, char *buff)
{
	int		nb_read;
	char	*tmp;
	char	*tmp2;
	int		tmp_read;

	nb_read = ft_strlen(*line);
	while ((tmp_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		nb_read += tmp_read;
		if ((tmp = ft_strchr(buff, '\n')))
		{
			*tmp = '\0';
			tmp2 = ft_strjoin(*line, buff);
			buff = ft_strcpy(buff, tmp + 1);
			free(*line);
			*line = tmp2;
			return (nb_read);
		}
		tmp2 = ft_strjoin(*line, buff);
		free(*line);
		*line = tmp2;
		ft_bzero(buff, BUFF_SIZE);
	}
	return ((tmp_read == -1) ? -1 : nb_read);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buff = NULL;
	int			nb_read;

	nb_read = 1;
	if (fd < 0 || !line)
		return (-1);
	if (!buff)
	{
		if (!(buff = ft_strnew(BUFF_SIZE)))
			return (-1);
		ft_bzero(buff, BUFF_SIZE);
		*line = NULL;
	}
	free (*line);
	if (read_buff(buff, line))
		nb_read = read_file(fd, line, buff);
	if (nb_read > 0)
		return (1);
	else
	{
		free(buff);
		buff = NULL;
		return (nb_read);
	}
}
