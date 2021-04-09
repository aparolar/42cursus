/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:34:09 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/09 11:39:22 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** search  c char into a str from the begining and 
** returns NULL if not encountered or pointer to the position
** of first ocurrence
*/

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*p_s;

	p_s = (char *)s;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (p_s[i] == (char)c)
			return (p_s + i);
		i++;
	}
	return (NULL);
}
