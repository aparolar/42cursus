/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:55:08 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/16 13:40:13 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*s2;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_calloc(1, 1));
	if (slen < start + len)
		len = slen - start;
	s2 = ft_calloc(len + 1, 1);
	if (s2)
		return (ft_memcpy(s2, s + start, len));
	return (0);
}
