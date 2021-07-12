/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 06:07:37 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/12 15:56:42 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_reset_t_printf(t_printf *tc)
{
	tc->arg = 0;
	tc->flag_minus = 0;
	tc->flag_zero = 0;
	tc->width = 0;
	tc->dot = 0;
	tc->precision = 0;
	tc->type = 0;
	tc->itsok = 0;
}