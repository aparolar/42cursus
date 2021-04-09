/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:52:07 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/09 11:20:39 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares n chars prom s1 pointer to s2 pointer
** if finded a difference returns diference of the two chars
** else returns 0
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*p_s1;
	char	*p_s2;

	p_s1 = (char *)s1;
	p_s2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (p_s1[i] != p_s2[i])
			return (p_s1[i] - p_s2[i]);
		i++;
	}
	return (0);
}
