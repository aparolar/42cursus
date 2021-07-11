/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:53:34 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/09 11:24:45 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	ft_parse_s(t_printf *tc)
{
	char	*s;

	s = va_arg(tc->args, char*);
	if (s)
	{
		//printf("%d",tc->flag_minus);
		if (tc->flag_minus > 0)
		{
			ft_putstr(s);
			ft_padding(tc->width - ft_strlen(s), ' ');
		}
		else if (tc->flag_zero > 0)
		{
			ft_padding(tc->width - ft_strlen(s), ' ');
			ft_putstr(s);
		}
		else
			ft_putstr(s);
	}
}
