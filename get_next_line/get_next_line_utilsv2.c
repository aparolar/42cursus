/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:21:52 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/28 09:47:06 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(char *str)
{
	char	*b;

	b = str;
	while (*b && *b != '\n')
		b++;
	return (b - str);
}

char	*ft_getmalloc(char *buff, char *str2)
{
	size_t	*bytes;

	bytes = ((size_t *)(buff + BUFFER_SIZE));
	if (!*buff && !str2)
	{
		*bytes = MAX
		return (malloc(sizeof(char)));
	}
	else if (!buff)
		new = malloc(ft_linelen(str2) * sizeof(char));
	else if (!str2)
		new = malloc(ft_linelen(str1) * sizeof(char));
	else
		new = malloc((ft_linelen(str1) + ft_linelen(str2)) * sizeof(char));
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new;
	char	*pnew;

	pnew = new;
	while (str1 && *str1 != '\0' && *str1)
	{
		*pnew = *str1;
		pnew++;
		str1++;
	}
	while (str2 && *str2 != '\0' && *str2)
	{
		*pnew = *str2;
		pnew++;
		str2++;
	}
	return (new);
}
