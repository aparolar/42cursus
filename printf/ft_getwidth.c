/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:41:31 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/22 14:51:27 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_getwidth(t_printf *tc)
{
	tc->width = 0;
	while (ft_isdigit(*tc->str))
	{
		tc->width *= 10;
		tc->width += *tc->str - 48;
		tc->str++;
	}
}
