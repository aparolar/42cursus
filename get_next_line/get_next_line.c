/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/21 22:51:40 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char *buff, char **line)
{
	int		len;
	char	*b;

	len = 0;
	b = buff;
	while (*b != '\n' && b < buff + BUFFER_SIZE - 1)
		len++;
	b = buff;
	*line = malloc((len + 1) * sizeof(char));
	if (*line)
	{
		while (*b != '\n' && b < buff + BUFFER_SIZE - 1)
		{
			**line = *b;
			b++;
		}
	}
	*((int *)(buff + BUFFER_SIZE)) = (buff + BUFFER_SIZE) - b;
	return ();
}

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + sizeof(int)];
	int			ret;
	int			*bytes;

	if (fd)
	{
		bytes = &buff[BUFFER_SIZE];
		ret = 1;
		while (ret)
		{
			if (*bytes > 0)
			{
				ret = get_line(&buff, &line);
			}
			else
			{
				ret = read(fd, &buff, BUFFER_SIZE);
				ret = get_line(&buff, &line);
			}
		}
	}
	return (-1);
}
