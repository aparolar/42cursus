/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:55:01 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/22 18:35:57 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_getprecision(t_conv *tc)
{
	tc->precision = 0;
	if (*tc->str == '.')
	{
		while (ft_isdigit(*(++tc->str)))
		{
			tc->precision *= 10;
			tc->precision += *tc->str - 48;
		}
	}
}
