/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:39:29 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/18 19:20:29 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static size_t	ft_find_max_str(char *str, char c)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c || !*(str + 1))
		{
			if (a > b)
			{
				b = a;
				a = 0;
			}
		}
		a++;
		str++;
	}
	return (b);
}
*/
static t_uint	ft_find_chars(char *str, char c)
{
	t_uint	len;

	len = 0;
	while (*str)
	{
		if (*str == c || !*(str + 1))
			if (*(str + 1) != c)
				len++;
		str++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	maxi;
	t_uint	i;
	char	**split;
	char	*s2;

	if (!s)
		return (0);
	s2 = (char *)s;
	maxi = ft_find_chars((char *)s, c);
	split = ft_calloc(maxi + 1, sizeof(split));
	i = 0;
	while (*s)
	{
		s = s2;
		while (*s2 && *s2 != c)
			s2++;
		if (i < maxi && *(s2 + 1))
			split[i] = ft_substr(s, 0, (t_uint)(s2 - s));
		s2++;
		i++;
	}
	split[i] = 0;
	return (split);
}
