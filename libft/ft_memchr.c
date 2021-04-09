/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:53:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/09 11:15:59 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the position + 1 of (char) c into the s only
** stops if superated n positions if s is null pointer
** returns NULL or not finded de char in the string
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p_s;

	if (!s)
		return (NULL);
	p_s = (char *)s;
	i = 0;
	while (i < n)
	{
		if (p_s[i] == (char)c)
			return (p_s + i);
	}
	return (NULL);
}
