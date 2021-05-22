/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:56:06 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/22 18:57:08 by aparolar         ###   ########.fr       */
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
	t_conv	sconv;

	if (!s || !*s)
		return (0);
	(&sconv)->str = (char *)s;
	(&sconv)->args = 0;
	va_start((&sconv)->pva, s);
	while (*(&sconv)->str)
	{
		if (*(&sconv)->str == '%')
		{
			(&sconv)->str++;
			ft_do_conv(&sconv);
		}
		else
			ft_putchar(*(&sconv)->str);
		(&sconv)->str++;
	}
	va_end((&sconv)->pva);
	return ((&sconv)->args);
}
