/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:21:52 by aparolar          #+#    #+#             */
/*   Updated: 2021/04/27 15:53:38 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	char	*b;

	b = str;
	while (*b != '\0')
		b++;
	return (b - str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new;
	char	*pnew;

	if (!str1 && !str2)
		new = malloc(sizeof(char));
	else if (!str1)
		new = malloc(ft_strlen(str2) * sizeof(char));
	else if (!str2)
		new = malloc(ft_strlen(str1) * sizeof(char));
	else
		new = malloc((ft_strlen(str1) + ft_strlen(str2)) * sizeof(char));
	pnew = new;
	while (str1 && *str1)
	{
		*pnew = *str1;
		pnew++;
		str1++;
	}
	while (str2 && *str2)
	{
		*pnew = *str2;
		pnew++;
		str2++;
	}
	return (new);
}
