/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:16:45 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/20 19:46:40 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

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


static void	ft_getflags(t_printf *tc)
{
	if (*tc->str && *tc->str == '0')
	{
		tc->str++;
		tc->flag_zero = 1;
	}
	if (*tc->str &&	*tc->str == '-')
	{
		tc->str++;
		tc->flag_minus = 1;
	}
	while (*tc->str == '0')
		tc->str++;
}

static int	ft_getnumber(t_printf *tc)
{
	char	*str;
	int		value;

	str = tc->str;
	if (*str == '*')
	{
		str++;
		value = va_arg(tc->args, int);
	}
	else
	{
		while (*str && ft_isdigit(*str))
			str++;
		value = ft_atoi(tc->str);
	}
	tc->str = str;
	return (value);
}

static void	ft_gettype(t_printf *tc)
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

static void	ft_getdot(t_printf *tc)
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
		if (*tc->str != '0' && (*tc->str == '*' || ft_isdigit((int)*tc->str)))
			tc->precision = ft_getnumber(tc);
		else
		{
			 if (*tc->str == '0')
			 {
				tc->zero_dot = 1;
				tc->str++;
			 }
			else
				tc->null_dot = 1;
		}
		ft_gettype(tc);
		return (ft_parsebypass(tc));
	}
	return (0);
}
