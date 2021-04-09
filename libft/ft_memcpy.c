/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:51:50 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/09 11:15:08 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies n char's from src pointer to dst pointer
** if src or dst are NULL returns NULL
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p_src;
	char	*p_dst;

	if (!src || !dst)
		return (NULL);
	p_src = (char *)src;
	p_dst = (char *)dst;
	i = 0;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (p_dst);
}
