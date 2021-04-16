/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:01:26 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/16 22:58:44 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		no;
	int		len;
	char	*pr;

	no = n;
	while (n > 0 || n < 0)
	{
		n /= 10;
		len++;
	}
	if (n < 0)
		len++;
	pr = (char *)ft_calloc(len + 1, 1);
	if (no < 0)
		*pr++ = '-';
	while (pr && no / 10 == 0)
	{
		*pr = no % 10 + 48;
		no /= 10;
		pr++;
	}
	return (pr);
}
