/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/05 17:25:38 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

int	get_line(char *fd, char *buff, char **line, int len)
{
	char	*new;
	char	*peb;

	new = ft_strcat(fd, buff);
	fd = new;
	peb = new;
	len = -1;
	while (*peb != '\n' && *peb)
		peb++;
	if (peb > fd && (*peb == '\n' || *peb == EOF))
	{
		*line = ft_substr(new, 0, peb - new);
		fd = ft_substr(new, peb - new + 1, len - (peb - new + 1));
		free(new);
	}
	else if (peb > fd)
		fd = new;
	return (len);
}

/*
**  el maximo de descriptores abiertos en el sistema viene determinado por
**  FD_SETSIZE por motivos de eficiencia de memoria lo reduzco a 256
*/

int	get_next_line(int fd, char **line)
{
	static char	**fds[256];
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
		ret = get_line((char *)fds[fd], buff, line, ret);
		if (*line && *line[ft_strlen(*line) - 1] == '\n')
			*line[ft_strlen(*line) - 1] = 0;
		if (ft_strlen(*line) > 0 && ft_strlen((char *)fds[fd]) > 0)
			return (1);
		if (ft_strlen(*line) > 0 && ft_strlen((char *)fds[fd]) == 0)
			return (0);
	}
	return (-1);
}
