/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:52:22 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/09 11:25:33 by aparolar         ###   ########.fr       */
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
	char	*p_src;
	char	*p_dst;

	p_src = (char *)src;
	p_dst = (char *)dst;
	i = 0;
	while (i < len)
	{
		p_dst[i] = p_src[i];
		i++;
	}
	return (p_dst);
}
