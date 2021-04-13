/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:53:15 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/13 17:31:22 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;

	if (!dst && !src)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (!dstsize || dstsize < dlen)
		return (slen + dstsize);
	if (slen + dlen > dstsize)
		slen = dstsize - dlen;
	dstsize = dlen + slen;
	//ft_memcpy(dst + dlen, src, slen);
	ft_strlcpy(dst + dlen, src, dstsize);
	dst[dstsize] = 0;
	return (dstsize);
}