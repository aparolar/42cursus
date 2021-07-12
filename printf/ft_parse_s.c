/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:53:34 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/12 18:28:54 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int		calc(t_printf *tc, char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (tc->dot)
	{
		if (tc->arg && len > tc->precision)
			len = tc->precision;
		else if (!tc->arg && tc->precision < len)
			len = 0;
	}
	return (len);
}

void	ft_parse_s(t_printf *tc)
{
	char	*s;
	int		len;
	int		i;

	s = va_arg(tc->args, char *);
	tc->arg = s;
	if (!s)
		s = "(null)";
	len = calc(tc, s);
	i = 0;
	if (!tc->flag_minus || (!tc->flag_minus && tc->width > len))
		ft_padding(tc->width - len, ' ');
	
	while (i < len)
	{
		ft_putchar(s[i++]);
	}
	if (tc->flag_minus)
		ft_padding(tc->width - len, ' ');
	tc->len += len;
}
