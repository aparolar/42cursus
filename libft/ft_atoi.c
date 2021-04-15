/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:10:39 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/15 18:02:19 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t			sign;
	int				num;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		sign = -1;
	printf("%s", str);
	while (ft_isdigit((int)*str))
	{
		num = (num * 10) + *str - 48;
		str++;
	}
	if (num > MAX_INT)
	printf("%lu\n", num * sign);
	/*
	while (str[++index] != 0)
	{
		if (str[index] >= '0' && str[index] <= '9')
			num = (num * 10) + str[index] - 48;
		else if (str[index] == '-' || str[index] == '+')
		{
			if (str[index] == '-')
				sign *= -1;
		}
		else if (num > 0 && str[index] != ' ' && str[index] != '\t' &&
				str[index] != '\f' && str[index] != '\n' &&
				str[index] != '\v' && str[index] != '\r')
			break ;
	}*/
	return (num * sign);
}
