/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:39:29 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/19 19:06:04 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_uint	ft_find_chars(char *str, char c)
{
	t_uint	len;

	len = 1;
	while (*str)
	{
		if (*str == c || !*(str + 1))
			if (*(str + 1) != c)
				len++;
		str++;
	}
	return (len);
}
/*
static char	*ft_get_substr_begins(char *str, char c)
{
	while (*str && *str == c)
		str++;
	return (str);
}
*/
/*
static char	*ft_get_substr_ends(char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (str);
}
*/

static char	**ft_get_split(char **split, char *s, char c)
{
	int		i;
	char	*s2;
	char	*s1;

	s1 = s;
	s2 = s1;
	i = 0;
	while (*s1)
	{
		while (*s1 == c)
			s1++;
		s2 = s1;
		while (*s2 && *s2 != c)
			s2++;
		if (s1 == s2)
			break ;
		split[i] = ft_calloc((s2 - s1 + 1), sizeof(char));
		ft_memcpy(split[i], s1, s2 - s1);
		s1 = s2;
		i++;
	}
	if (i == 0)
		return (NULL);
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	t_uint	maxi;
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
	return (ft_get_split(split, (char *)s, c));
}
/*
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
	split = ft_calloc(maxi, sizeof(char **));
	if (!split)
		return (0);
	i = 0;
	while (*s1)
	{
		s1 = ft_get_substr_begins(s2, c);
		s2 = ft_get_substr_ends(s1, c);
		split[i] = ft_substr(s1, 0, (t_uint)(s2 - s1));
		s2++;
		i++;
	}
	return (split);
}
*/