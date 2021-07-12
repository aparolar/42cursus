/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:53:34 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/12 12:15:27 by aparolar         ###   ########.fr       */
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
		if (len > tc->precision)
			len = tc->precision;
	}
	//if (tc->width > 0)
	//	len = tc->width - len;
	return (len);
}

void	ft_parse_s(t_printf *tc)
{
	char	*s;
	int		len;
	int		i;

	s = va_arg(tc->args, char *);
	if (!s)
		s = "(null)";
	len = calc(tc, s);
	i = 0;
	if ((tc->flag_zero > 0 || tc->width > len) && tc->width + tc->precision > len)
	{
		ft_padding(tc->width - len, ' ');
		tc->len += tc->width - len;
	}
	while (i < len)
		ft_putchar(s[i++]);
	if (tc->flag_minus > 0 && tc->width + tc->precision > len)
	{
		ft_padding(tc->width - len, ' ');
		tc->len += tc->width;
	}
	tc->len += len;
}
