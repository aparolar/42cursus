/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 06:39:47 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/12 23:11:38 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_padding(int width, char c)
{
	int	ret;

	ret = width;
	if (ret < 0)
		ret = 0;
	while (width-- > 0)
		ft_putchar(c);
	return (ret);
}