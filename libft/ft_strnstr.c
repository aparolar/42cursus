/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:48:14 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/12 18:21:35 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ln;
	size_t	lh;

	i = 0;
	ln = ft_strlen(needle);
	lh = ft_strlen(haystack);
	if (!ln)
		return (haystack);
	while (i < len && len - i >= ln)
	{
		if (ft_memcmp(haystack[i], needle, ln))
			return (((char *)haystack) + i);
	}
	return (NULL);
}

