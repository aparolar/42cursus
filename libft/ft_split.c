/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:39:29 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/19 13:06:12 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*ft_get_substr_begins(char *str, char c)
{
	while (*str && *str == c)
		str++;
	return (str);
}

static char	*ft_get_substr_ends(char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	t_uint	maxi;
	t_uint	i;
	char	**split;
	char	*s2;
	char	*s1;

	if (!s)
		return (0);
	s1 = (char *)s;
	s2 = s1;
	maxi = ft_find_chars(s1, c);
	if (!maxi)
		return (0);
	split = ft_calloc(maxi, sizeof(char *));
	if (!split)
		return (0);
	i = 0;
	while (*s1)
	{
		s1 = ft_get_substr_begins(s2, c);
		s2 = ft_get_substr_ends(s1, c);
		if (i <= maxi)
			split[i] = ft_substr(s1, 0, (t_uint)(s2 - s1));
		s2++;
		i++;
	}
	return (split);
}
