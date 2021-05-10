/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/10 17:29:08 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strrem(const char *s, size_t start, size_t len)
{
	char	*st;
	char	*st2;
	char	*s1;

	s1 = (char *)s;
	st = 0;
	if (start < ft_strlen(s))
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		st = ft_calloc(ft_strlen(s) - len + 1, sizeof(char));
		st2 = st;
		while (*s1)
		{
			if ((size_t)(s1 - s) < start || (size_t)(s1 - s) > start + len - 1)
			{
				st[st2 - st] = *s1;
				st2++;
			}
			s1++;
		}
	}
	else
		st = ft_calloc(1, sizeof(char));
	return (st);
}

static int	get_line(char **buffer, char **line)
{
	char	*s;
	int		ret;

	s = *buffer;
	ret = 0;
	if (!*buffer)
		*line = ft_calloc(1, sizeof(char));
	else if (!ft_strchr(s, '\n'))
		*line = s;
	else
	{
		*line = ft_substr(s, 0, ft_strchr(s, '\n') - s);
		s = ft_strrem(s, 0, ft_strchr(s, '\n') - s + 1);
		free(*buffer);
		*buffer = s;
		ret = 1;
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*list[4096];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (read(fd, buff, 0) < 0 || !line || BUFFER_SIZE < 1 )
		return (-1);
	*line = 0;
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = 0;
		if (!list[fd])
			list[fd] = ft_calloc(1, sizeof(char));
		tmp = list[fd];
		list[fd] = ft_strcat(tmp, buff);
		free(tmp);
		tmp = 0;
		if (ft_strchr(list[fd], '\n'))
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	return (get_line(&list[fd], line));
}
