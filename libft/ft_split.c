/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:39:29 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/17 18:07:26 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static size_t	ft_find_chars(char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str == c || !*(str + 1))
			c++;
		str++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	maxl;
	size_t	maxi;
	char	**split;

	if (!s)
		return (0);
	maxl = ft_find_chars(s, c);
	maxi = ft_find_chars(s, c);
	split = (char **)ft_calloc(maxi, maxl);
	while ()
}
