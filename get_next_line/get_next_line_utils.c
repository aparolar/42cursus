/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:21:52 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/30 01:23:05 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	char	*pbuff;

	pbuff = str;
	while (*pbuff)
		pbuff++;
	return (pbuff - str);
}

char	*ft_memcpy(char *s1, char *s2, size_t n)
{
	char	*ps1;

	ps1 = s1;
	while (n > 0)
	{
		ps1[n - 1] = s2[n - 1];
		n--;
	}
	return (ps1);
}

void	*slloc(size_t bytes)
{
	void	*ret;

	if (bytes == 0)
		bytes = 1;
	ret = malloc(bytes);
	if (!ret)
		return (0);
	*((size_t *)(ret + (bytes - 1))) = 0;
	return (ret);
}
