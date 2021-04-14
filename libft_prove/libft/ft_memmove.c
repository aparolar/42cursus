/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:52:22 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/11 13:54:16 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies all chars from src pointer to dst pointer
** the strings may be overlaped
** returns pointer to dst
*/

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t	i;

	if (!src && !dst && len)
		return (NULL);
	i = 0;
	if (src < dst)
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
