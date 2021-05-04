/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/04 20:24:55 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char *fd, char *buff, char **line, int len)
{
	char	*new;
	char	*peb;

	new = ft_strcat(fd, buff);
	free(fd);
	fd = new;
	peb = fd;
	while (*peb != '\n' && *peb)
		peb++;
	*line = ft_calloc(peb - buff, sizeof(char));
}

/*
**  el maximo de descriptores abiertos en el sistema viene determinado por
**  FD_SETSIZE por motivos de eficiencia de memoria lo reduzco a 256
*/

int	get_next_line(int fd, char **line)
{
	static char	fds[256];
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	ft_bzero(buff, BUFFER_SIZE);
	if (fd < 0 && !line && BUFFER_SIZE < 1)
		return (-1);
	if (!(fds[fd]))
		fds[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!read(fd, fds[fd], 0))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		ret = get_line(fds[fd], buff, line, ret);
		if (ret <= 1)
			return (ret);
	}
}
