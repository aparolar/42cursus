/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icastell <icastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:42:49 by icastell          #+#    #+#             */
/*   Updated: 2021/11/03 18:54:42 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
	size_t  i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(const char *str)
{
	size_t  longitud;
	int     i;
	char    *ptr;

	i = 0;
	longitud = ft_strlen(str);
	ptr = malloc(longitud + 1);
	if (!ptr)
		return (NULL);
	else
	{
		while (str[i] != '\0')
		{
			ptr[i] = str[i];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

char    *ft_strjoin(char *s1, char *s2)
{
	size_t  i;
	size_t  long1;
	size_t  long2;
	char    *str;

	if ((!s1) || (!s2))
		return (NULL);
	i = 0;
	long1 = ft_strlen(s1);
	long2 = ft_strlen(s2);
	str = malloc((long1 + long2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i - long1] != '\0')
	{
		str[i] = s2[i - long1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char    buffer[1];
	char    *line;
	ssize_t num_datos;

	//buffer[1] = '\0';
	num_datos = read(fd, buffer, ((BUFFER_SIZE * 0) + 1));
	if (num_datos <= 0)
		return (NULL);
	if (num_datos > 0)
		line = ft_strdup("");
	while (num_datos > 0)
	{
		if (buffer[0] == '\n')
			break;
		line = ft_strjoin(line, buffer);
		num_datos = read(fd, buffer, 1);
	}
	return (line);
}

int main(void)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		write(1, line, strlen(line));
		write(1, "\n", 1);
		free(line);
		line = get_next_line(0);
	}
	system("leaks prueba");//get_next_line");
	return (0);
}
