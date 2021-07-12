/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:16:45 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/11 23:23:35 by aparolar         ###   ########.fr       */
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
**		.	Presicion only for float
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
	tc->str = str;
	//printf("\n[%c<>%d]\n", *str, value);
	//printf("\n%lu - %lu\n", (u_long)(tc)->str, (u_long)str);
	return (value);
}

void	ft_gettype(t_printf *tc)
{
	char	*str;

	str = TYPES;
	while (*tc->str && *str)
	{
		//printf("%c == %c\n", *tc->str, *str);
		if (*tc->str == *str)
		{
			//printf("I'm here\n");
			tc->type = *str;
			//printf("{%c}", tc->type);
			break ;
		}
		str++;
	}
	//printf("\n[%c - %c]\n", *str, tc->type);
}

void	ft_getdot(t_printf *tc)
{
	if (*tc->str && *tc->str == '.')
	{
		//printf("\ndot\n");
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
