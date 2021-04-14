/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:53:15 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/14 13:36:13 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	tlen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	tlen = slen;
	if (dstsize < dlen)
		return (dstsize + slen);
	if (dstsize > 0 && slen)
	{
		if (dlen + slen > dstsize - 1)
			tlen = dstsize - dlen;
		ft_memcpy(dst + dlen, src, tlen);
	}
	dst[dlen + tlen] = 0;
	return (dlen + slen - 1);
}
/*
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (dstsize < i)
	{
		while (src[j])
			j++;
		return (dstsize + j);
	}
	while (dstsize > 0 && i < dstsize - 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	while (src[j++])
		i++;
	return (i);
}*/
