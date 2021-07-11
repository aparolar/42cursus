/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebypass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:07:21 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/09 05:27:45 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_parsebypass(t_printf *tc)
{
	if (ft_check_arg(tc))
	{
		if (tc->type == 'c')
			ft_parse_c(tc);
		else if (tc->type == 's')
			ft_parse_s(tc);
		else if (tc->type == 'p')
			ft_parse_p(tc);
		else if (tc->type == 'd')
			ft_parse_d(tc);
		else if (tc->type == 'i')
			ft_parse_i(tc);
		else if (tc->type == 'u')
			ft_parse_u(tc);
		else if (tc->type == 'x')
			ft_parse_x(tc);
		else if (tc->type == 'X')
			ft_parse_X(tc);
		else if (tc->type == '%')
			ft_parse_perback(tc);
	}
	return (tc->itsok);
}
