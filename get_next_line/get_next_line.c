/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:17:56 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/27 16:21:00 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char *buff, char **line)
{
	int		bytes;
	char	*b;

	b = ft_strjoin(buff, *line);
	free(*line);
	*line = b;
	return (*((int *)(buff + BUFFER_SIZE)));
}

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + sizeof(int)];
	int			ret;
	int			*bytes;

	ret = 0;
	if (fd)
	{
		bytes = ((int *)(buff + BUFFER_SIZE));
		while (ret >= 0)
		{
			if (*bytes > 0 && ret > 0)
			{
				ret = get_line(buff, line);
			}
			else
			{
				*bytes = 0;
				ret = read(fd, buff, BUFFER_SIZE);
				ret = get_line(buff, line);
			}
		}
	}
	return (ret);
}
