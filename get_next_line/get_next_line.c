/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/30 16:11:35 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_line(char *buff, size_t bytes, char **line)
{
	char	*pbuff;
	char	*pebuff;
	char	*new;

	pbuff = buff + (BUFFER_SIZE - bytes);
	pebuff = pbuff;
	while ((!*pbuff || *pbuff == '\n') && pbuff - buff < BUFFER_SIZE)
		pbuff++;
	if (pbuff - buff < BUFFER_SIZE)
	{
		pebuff = pbuff;
		while (*pebuff && *pebuff != '\n' && pebuff - buff < BUFFER_SIZE)
		{
			if (*pebuff == '\n' || *(pebuff + 1) == '\n')
				*((int *)(buff + BUFFER_SIZE + sizeof(int))) = 1;
			pebuff++;
		}
		if (!*line)
			*line = ft_calloc(1, sizeof(char));
		new = ft_strcat(*line, pbuff);
		free(*line);
		*line = new;
	}
	return (BUFFER_SIZE - (pebuff - buff));
}

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + sizeof(int) + sizeof(int)];
	int			*ret;
	int			*endline;

	if (fd)
	{
		if (*line)
			free(*line);
		ret = ((int *)(buff + BUFFER_SIZE));
		endline = (int *)((buff + BUFFER_SIZE + sizeof(int)));
		*endline = 0;
		*ret = 0;
		while (*ret != EOF)
		{
			if (*ret > 0)
				*ret = get_line((char *)buff, *ret, line);
			else
				*ret = read(fd, (char *)buff, BUFFER_SIZE);
			if (*endline && *ret != EOF)
				return (1);
		}
		return (0);
	}
	return (-1);
}
