/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:39:29 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/19 00:43:35 by aparolar         ###   ########.fr       */
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

static const char	*ft_get_substr_begins(const char *str, char c)
{
	while (*str && *str == c)
		str++;
	return (str);
}

static const char	*ft_get_substr_ends(const char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (str);
}

static char	*ft_split_free(const char **split)
{
	while (*split)
	{
		free((void *)split);
		split++;
	}
	free((void *)split);
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	t_uint	maxi;
	t_uint	i;
	char	**split;
	char	*s2;

	if (!s)
		return (0);
	s2 = (char *)s;
	maxi = ft_find_chars((char *)s, c);
	if (!maxi)
		return (0);
	split = ft_calloc(maxi + 1, sizeof(split));
	if (!split)
		return (0);
	i = 0;
	while (*s)
	{
		s = (char *)ft_get_substr_begins(s2, c);
		s2 = (char *)ft_get_substr_ends(s, c);
		if (i <= maxi)
			split[i] = ft_substr(s, 0, (t_uint)(s2 - s));
		s2++;
		i++;
	}
	split[i] = 0;
	return (split);
}
