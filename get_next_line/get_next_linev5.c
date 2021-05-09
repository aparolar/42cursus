/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/08 15:00:02 by aparolar         ###   ########.fr       */
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

static char	*get_line(char **fd, char *buff, char **line, int *ret)
{
	char	*new;
	char	*n1;
	char	*peb;

	new = ft_strcat(*fd, buff);
	n1 = new;
	peb = new;
	*ret = 0;
	while (*peb && *peb != '\n')
		peb++;
	if (*peb != '\n' && ft_strlen(buff) == BUFFER_SIZE)
		peb = new;
	if (peb > new || (*peb == '\n'))
	{
		*line = 0;
		*ret = peb - new;
		*line = ft_substr(new, 0, *ret);
		peb = ft_strrem(new, 0, *ret + 1);
		free(new);
		new = peb;
	}
	free(*fd);
	return (new);
}

/*
**  el maximo de descriptores abiertos en el sistema viene determinado por
**  FD_SETSIZE por motivos de eficiencia de memoria lo reduzco a 256
*/

int	get_next_line(int fd, char **line)
{
	static char	*fds[4096];
	char		buff[BUFFER_SIZE + 1];
	int			ret[2];

	ret[0] = -1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (ret[0]);
	if (!(fds[fd]))
		fds[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (read(fd, buff, 0) == 0)
	{
		ret[0] = read(fd, buff, BUFFER_SIZE);
		buff[ret[0]] = 0;
		if (ft_strlen(fds[fd]) > 0 || ft_strlen(buff) > 0)
			fds[fd] = get_line(&fds[fd], buff, line, &ret[1]);
		if (ret[0] == 0 && fds[fd][0] == 0)
			break ;
		else if (*line && fds[fd][0] != 0)
			return (1);
	}
	if (fds[fd])
		free(fds[fd]);
	return (ret[0]);
}
