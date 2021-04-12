/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:40:12 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/12 11:06:47 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** search a first coincidence of c value along the s string begining
** from the end an returns his position or NULL if not encountered
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*p_s;

	p_s = (char *)s;
	len = ft_strlen(s);
	if (!c)
		return (p_s + len);
	if (!len)
		return (NULL);
	while (--len > 0)
	{
		if (p_s[len] == (char)c)
			return (p_s + len);
		else if (!(len - 1) && p_s[0] == (char)c)
			return (p_s);
	}
	return (NULL);
}
