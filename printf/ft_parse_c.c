/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:49:25 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/15 15:59:08 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	ft_parse_c(t_printf *tc)
{
	int	c;

	c = va_arg(tc->args, int);
	if (tc->width > 0 && !tc->flag_minus)
		tc->len += ft_padding(tc->width - 1, ' ');
	ft_putchar(c);
	tc->len++;
	if (tc->width > 0 && tc->flag_minus)
		tc->len += ft_padding(tc->width - 1, ' ');
}
