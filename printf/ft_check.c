/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:48:07 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/20 10:28:04 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_arg(t_printf *tc)
{
	tc->itsok = 0;
	if (tc->width < 0)
	{
		tc->width = -tc->width;
		tc->flag_minus = 1;
	}
	if (tc->precision < 0)
		tc->precision = 0;
	if (tc->flag_minus && tc->flag_zero)
		tc->flag_zero = 0;
	if (tc->type)
		tc->itsok = 1;
	return (tc->itsok);
}
