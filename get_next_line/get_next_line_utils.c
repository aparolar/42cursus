/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:21:52 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/09 12:02:49 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	char	*pbuff;

	if (!str)
		return (0);
	pbuff = (char *)str;
	while (*pbuff)
		pbuff++;
	return (pbuff - str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*sd;

	sd = (char *)s;
	while (*sd)
	{
		if (*sd == (char)c)
			return (sd);
		sd++;
	}
	return (0);
}
/*
char	*ft_bzero(const char *s, size_t n)
{
	char	*ps;

	ps = (char *)s;
	while (n > 0)
		*(ps + --n) = 0;
	return (ps);
}
*/

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*st;
	char	*s1;

	s1 = (char *)s;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	st = ft_calloc(len + 1, sizeof(char));
	if (st)
	{
		while (len > 0)
		{
			st[len - 1] = s1[start + len - 1];
			len--;
		}
		return (st);
	}
	return (0);
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
		ret = ft_calloc(ft_strlen(ps1) + ft_strlen(ps2) + 1, sizeof(char));
		if (ret)
		{
			while (*ps1)
			{
				ret[ps1 - s1] = *ps1;
				ps1++;
			}
			while (*ps2)
			{
				ret[(ps1 - s1) + (ps2 - s2)] = *ps2;
				ps2++;
			}
			return (ret);
		}
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	size *= count;
	ret = malloc(size);
	if (!ret)
		return (0);
	while (size > 0)
		ret[--size] = 0;
	return (ret);
}

/*
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
*/
