/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:56:06 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/09 11:29:24 by aparolar         ###   ########.fr       */
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
		if (!(&tc)->itsok)
		{	
			(&tc)->str = str;
			ft_putchar(*(&tc)->str);
		}
		else
			return (0);
		//printf("%s\n", str);
		(&tc)->str++;
	}
	va_end((&tc)->args);
	return (1);
}
