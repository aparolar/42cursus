/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:56:16 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/21 14:48:51 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int	calc(t_printf *tc, char *str, int value)
{
	int	len;

	tc->o_width = tc->width;
	tc->o_prec = tc->precision;
	len = 0;
	if (value < 0)
		len = 1;
	if (tc->precision > ft_intlen(value))
		tc->precision -= ft_intlen(value);
	else
		tc->precision = 0;
	len += tc->precision + ft_intlen(value);
	if (tc->precision + ft_intlen(value) >= tc->width)
		tc->width = 0;
	else
	{
		if (tc->width > len)
			tc->width -= len;
		else
			tc->width = 0;
		len += tc->width;
	}
	return (len);
}

static void	print_flag_zero(t_printf *tc, int value, char *str)
{
	if (tc->flag_zero && tc->dot)
		ft_padding(tc->width, ' ');
	if (value < 0)
		ft_putchar('-');
	if (!tc->dot && tc->flag_zero)
		ft_padding(tc->width, '0');
	else
		ft_padding(tc->precision, '0');
	if (value < 0)
		ft_putstr(str + 1);
	else
		ft_putstr(str);
	if (tc->flag_minus)
		ft_padding(tc->width, ' ');
}

static void	print_flag_minus(t_printf *tc, int value, char *str)
{
	if (tc->flag_zero && tc->dot)
		ft_padding(tc->width, ' ');
	if (value < 0)
		ft_putchar('-');
	if (!tc->dot && tc->flag_zero)
		ft_padding(tc->width, '0');
	else
		ft_padding(tc->precision, '0');
	if (value < 0)
		ft_putstr(str + 1);
	else
		ft_putstr(str);
	if (tc->flag_minus)
		ft_padding(tc->width, ' ');
}

static void	print_default(t_printf *tc, int value, char *str)
{
	if (tc->dot && (tc->null_dot || tc->zero_dot))
	{
		if (tc->zero_dot && value != 0)
			tc->len += ft_putstr(str);
		else if (tc->null_dot)
		{
			if (value != 0)
			{
				tc->len += ft_padding(tc->o_width - ft_strlen(str), ' ');
				tc->len += tc->o_width + ft_putstr(str);
			}
			else
				tc->len += ft_padding(tc->o_width, ' ');
		}
	}
	else
	{
		tc->len += ft_padding(tc->width, ' ');
		if (value < 0)
		{
			tc->len += ft_putchar(*str);
			str++;
		}
		tc->len += ft_padding(tc->o_prec - ft_strlen(str), '0');
		tc->len += ft_putstr(str);
	}
}

static void	print_default_minus(t_printf *tc, int value, char *str)
{
	if (tc->dot && (tc->null_dot || tc->zero_dot))
	{
		if (tc->zero_dot && value != 0)
		{
			tc->len += ft_putstr(str);
			tc->len += ft_padding(tc->o_width - ft_strlen(str), ' ');
		}
		else if (tc->null_dot)
		{
			if (value != 0)
			{
				tc->len += tc->o_width + ft_putstr(str);
				tc->len += ft_padding(tc->o_width - ft_strlen(str), ' ');
			}
			else
				tc->len += ft_padding(tc->o_width, ' ');
		}
	}
	else
	{
		if (value < 0)
		{
			tc->len += ft_putchar(*str);
			str++;
		}
		tc->len += ft_padding(tc->o_prec - ft_strlen(str), '0');
		tc->len += ft_putstr(str);
		tc->len += ft_padding(tc->width, ' ');
	}
}

void	ft_parse_d(t_printf *tc)
{
	char    *pstr;
	int		value;
	int		len;

	value = va_arg(tc->args, int);
	pstr = ft_itoa(value);
	len = calc(tc, pstr, value);
	if (tc->flag_zero)
	{
		print_flag_zero(tc, value, pstr);
		tc->len += len;
	}
	else if (tc->flag_minus)
	{
		//print_flag_minus(tc, value, pstr);
		//tc->len += len;
		print_default_minus(tc, value, pstr);
	}
	else
		print_default(tc, value, pstr);
	free(pstr);
}