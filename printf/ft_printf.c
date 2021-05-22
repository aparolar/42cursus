/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:56:06 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/22 23:20:26 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

/*
**  %[flags][width][.precision]type
*/

void	ft_do_conv(t_conv *tc)
{
	tc->args++;
	ft_getpadding(tc);
	ft_getwidth(tc);
	ft_getprecision(tc);
	printf("\nlpadd = %d rpadd = %d width = %d precision = %d\n", tc->lpadd, tc->rpadd, tc->width, tc->precision);
}

int		ft_printf(const char *s, ...)
{
	t_conv	tc;

	if (!s || !*s)
		return (0);
	(&tc)->str = (char *)s;
	(&tc)->args = 0;
	va_start((&tc)->pva, s);
	while (*(&tc)->str)
	{
		if (*(&tc)->str == '%')
		{
			(&tc)->str++;
			ft_do_conv(&tc);
		}
		else
			ft_putchar(*(&tc)->str);
		(&tc)->str++;
	}
	va_end((&tc)->pva);
	return ((&tc)->args);
}
