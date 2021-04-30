/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:21:52 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/30 15:38:11 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	char	*pbuff;

	if (!str)
		return (0);
	pbuff = str;
	while (*pbuff)
		pbuff++;
	return (pbuff - str);
}

char	*ft_memcpy(char *s1, const char *s2, size_t n)
{
	char	*ps1;
	char	*ps2;

	ps1 = (char *)s1;
	ps2 = (char *)s2;
	while (n > 0)
	{
		ps1[n - 1] = ps2[n - 1];
		n--;
	}
	return (ps1);
}

char	*ft_strcat(const char *s1, const char *s2)
{
	char	*ret;
	char	*ps1;
	char	*ps2;

	if (s1 && s2)
	{
		ps1 = (char *)s1;
		ps2 = (char *)s2;
		ret = (char *)ft_calloc(ft_strlen(ps1) + ft_strlen(ps2), sizeof(char));
		if (ret)
		{
			ft_memcpy(ret, ps1, ft_strlen(ps1));
			ft_memcpy(ret + ft_strlen(ps1), ps2, ft_strlen(ps2));
			return (ret);
		}
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	count *= size;
	ret = malloc(size);
	if (!ret)
		return (0);
	while (size > 0)
	{
		*((char *)(ret + size - 1)) = 0;
		size--;
	}
	return (ret);
}
