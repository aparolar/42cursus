/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/22 16:19:49 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_buffer(char *buff, int *start, int *len)
{
	int		*bytes;
	char	*b2;

	bytes = (int *)buff + BUFFER_SIZE;
	if (*bytes)
	{

	}
	else
	{
		*start = 0;
		while (*(buff + *len) != '\n' && buff + *len < buff + BUFFER_SIZE - 1)
			len++;
	}
	return (*bytes);
}

int	get_line(char *buff, char **line)
{
	int		len;
	int		bytes;
	int		start;
	char	*b;

	len = 0;
	b = buff;
	bytes = get_buffer(buff, &start, &len);
	if (bytes)
	{
		len = BUFFER_SIZE - bytes;
	}
	b = buff;
	*line = malloc((len + 1) * sizeof(char **));
	line[len + 1 * sizeof(char)] = 0;
	if (*b)
	{
		while (b <= (buff + len))
		{
			*((*line) + (b - buff)) = *b;
			b++;
		}
	}
	bytes = (buff + BUFFER_SIZE) - b;
	return (bytes);
}

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + sizeof(int)];
	int			ret;
	int			*bytes;

	if (fd)
	{
		bytes = (int *)buff + BUFFER_SIZE;
		ret = 1;
		while (ret)
		{
			if (*bytes > 0)
			{
				ret = get_line(buff, line);
			}
			else
			{
				ret = read(fd, buff, BUFFER_SIZE);
				ret = get_line(buff, line);
			}
		}
	}
	return (-1);
}
