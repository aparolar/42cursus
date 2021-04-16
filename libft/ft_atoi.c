/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:10:39 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/16 09:44:04 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long		num;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		if (num * sign > MAX_INT)
			return (-1);
		else if (num * sign < MIN_INT)
			return (0);
		num = (num * 10) + *str - 48;
		str++;
	}
	num *= sign;
	return (num);
}
