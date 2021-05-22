/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:57:53 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/22 18:54:09 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"

/*
**  structs;
**
*/

typedef struct	s_conv
{
	char	*str;
	va_list	pva;
	int		lpadd;
	int		rpadd;
	int		precision;
	int		width;
	char	type;
	int		args;
}			t_conv;

int		ft_printf(const char *s, ...);
void	ft_getwidth(t_conv *tc);
void	ft_getpadding(t_conv *tc);
void	ft_getprecision(t_conv *tc);

#endif
