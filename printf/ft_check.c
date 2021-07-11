/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:48:07 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/09 05:45:58 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_arg(t_printf *tc)
{
	tc->itsok = 0;
	if (tc->flag_minus && tc->flag_zero)
		tc->flag_zero = 0;
	if (tc->type)
		tc->itsok = 1;
	return (tc->itsok);
}
