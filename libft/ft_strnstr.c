/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:48:14 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/12 22:29:00 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	lh;
	size_t	ln;

	i = 0;
	lh = ft_strlen(haystack);
	ln = ft_strlen(needle);
	if (!len || haystack == needle)
		return ((char *)haystack);
	if (ln > lh && lh < len)
		return (NULL);
	while (i < lh && lh - i > len)
	{
		//printf("len = %lu i = %lu string = %s\n", len, i, ((char *)haystack) + i);
		if (!ft_strncmp(((char *)haystack) + i, needle, len))
			return (((char *)haystack) + i);
		i++;
	}
	return (NULL);
}

