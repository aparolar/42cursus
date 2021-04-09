/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:53:37 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/09 13:56:45 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** puts char c value into b pointer along de len chars
** returns b pointer
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*p_b;

	if (!len)
		return (NULL);
	p_b = (char *)b;
	i = 0;
	while (i < len)
	{
		p_b[i] = (char)c;
		i++;
	}
	return (p_b);
}
