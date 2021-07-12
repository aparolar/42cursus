/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:16:45 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/12 15:40:00 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**  %[flags][width][.precision]type
**	flags
**		-	Rigth align blank-padding
**		0	Left align zero-padding overrides - flag
**	Width
**		padding size
**	dot
**		.	Precision only truncates str
**	precision
**		presicion size
**	type
**		cspdiuxX%	only one of dis set
*/


void	ft_getflags(t_printf *tc)
{
	if (*tc->str && *tc->str == '-')
	{
		tc->str++;
		tc->flag_minus = 1;
	}
	else if (*tc->str && *tc->str == '0')
	{
		tc->str++;
		tc->flag_zero = 1;
	}
}

int		ft_getnumber(t_printf *tc)
{
	char	*str;
	int		value;

	str = tc->str;
	while (*str && ft_isdigit(*str))
		str++;
	value = ft_atoi(tc->str);
	//if (*tc->str == '0')
	//	value = 0;
	tc->str = str;
	return (value);
}

void	ft_gettype(t_printf *tc)
{
	char	*str;

	str = TYPES;
	while (*tc->str && *str)
	{
		if (*tc->str == *str)
		{
			tc->type = *str;
			break ;
		}
		str++;
	}
}

void	ft_getdot(t_printf *tc)
{
	if (*tc->str && *tc->str == '.')
	{
		tc->dot = 1;
		tc->str++;
	}
}

int		ft_preparse(t_printf *tc)
{
	if (*tc->str == '%')
	{
		tc->str += 1;
		ft_getflags(tc);
		tc->width = ft_getnumber(tc);
		ft_getdot(tc);
		tc->precision = ft_getnumber(tc);
		ft_gettype(tc);
		return (ft_parsebypass(tc));
	}
	return (0);
}
