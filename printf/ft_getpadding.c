/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:34:18 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/22 18:35:24 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_getpadding(t_conv *tc)
{
	tc->lpadd = 0;
	tc->rpadd = 0;
	if (*tc->str == '0')
	{
		tc->lpadd = 1;
		while (*tc->str == '0')
			tc->str++;
	}
	if (*tc->str == '-')
	{
		tc->lpadd = 0;
		tc->rpadd = 1;
		while (*tc->str == '0' || *tc->str == '-')
			tc->str++;
	}
}
