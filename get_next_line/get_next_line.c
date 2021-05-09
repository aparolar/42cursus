/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/09 22:57:30 by aparolar         ###   ########.fr       */
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

static char	*get_line(char **fd, char **line, int *ret)
{
	char	*s;
	char	*si;
	char	*st;

	s = *fd;
	if (!ft_strchr(s, '\n'))
	{
		*line = ft_substr(s, 0, ft_strlen(s));
		free(*fd);
	}
	else
	{
		*line = ft_substr(s, 0, )
	}
}

/*
**  el maximo de descriptores abiertos en el sistema viene determinado por
**  FD_SETSIZE por motivos de eficiencia de memoria lo reduzco a 256
*/

int	get_next_line(int fd, char **line)
{
	static char	*fds[4096];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = 0;
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = 0;
		if (!fds[fd])
			fds[fd] = ft_calloc(1, sizeof(char));
		tmp = fds[fd];
		fds[fd] = ft_strcat(fds[fd], buff);
		free(tmp);
		if (ft_strchr(fds[fd], '\n'))
			break ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	return (get_line(&fds[fd], line, &ret));
}
