/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bekram <bekram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:56:06 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/11 17:33:55 by bekram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

/*
**  %[flags][width][.precision]type
*/

int	ft_printf(const char *s, ...)
{
	t_printf	tc;
	char		*str;

	if (!s || !*s)
		return (0);
	(&tc)->str = (char *)s;
	va_start((&tc)->args, s);
	while (*(&tc)->str)
	{
		str = (&tc)->str;
		ft_reset_t_printf(&tc);
		ft_preparse(&tc);
		if  (!(&tc)->itsok)
			(&tc)->str = str;
		ft_putchar(*(&tc)->str);
		(&tc)->str++;
	}
	va_end((&tc)->args);
	return (1);
}
