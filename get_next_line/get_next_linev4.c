/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/06 21:52:39 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*s2;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_calloc(1, sizeof(char)));
	if (slen < start + len)
		len = slen - start;
	s2 = ft_calloc(len + 1, sizeof(char));
	if (s2)
		return (ft_memcpy(s2, s + start, len));
	return (0);
}

static char	*get_line(char **fd, char *buff, char **line, int len)
{
	char	*new;
	char	*peb;

	new = ft_strcat(*fd, buff);
	if (fd)
		free(*fd);
	*fd = new;
	peb = new;
	while (*peb != '\n' && *peb != 0)
		peb++;
	if (peb > *fd && (*peb == '\n' || *peb == EOF))
	{
		*line = ft_substr(new, 0, peb - new);
		return (ft_substr(new, peb - new + 1, (peb - new + 1)));
	}
	else if (peb == *fd && (*peb == '\n' || *peb == EOF))
	{
		*line = ft_calloc(1, sizeof(char));
		return (ft_substr(new, peb - new + 1, (peb - new + 1)));
	}
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
	int			ret;

	ft_bzero(buff, BUFFER_SIZE + 1);
	if (fd < 0 && !line && BUFFER_SIZE < 1)
		return (-1);
	if (!(fds[fd]))
		fds[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (read(fd, buff, 0) >= 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		ret = read(fd, buff, BUFFER_SIZE);
		fds[fd] = get_line(&fds[fd], buff, line, ret);
		if (*line && ft_strlen(fds[fd]) > 0 && ret > 0)
		{
			free(fds[fd]);
			return (1);
		}
		else if (*line && !ret)
		{
			*line = fds[fd];
			return (0);
		}
	}
	return (-1);
}
