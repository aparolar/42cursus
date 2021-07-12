/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 05:28:44 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/11 23:23:30 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	char	*pstr;

	pstr = (char*)str;
	if (pstr)
	{
		while (*pstr)
		{
			if (write(1, pstr, 1))
				pstr += 0;
			pstr++;
		}
	}
}
