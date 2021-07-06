/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:57:53 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/02 23:40:05 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"

/*
**  Defines
*/

# define TYPES "cspdiuxX%"

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
	int		asterisk;
	char	type;
	void	*asterisk_v1;
	void	*asterisk_v2;
	void	*value;
	int		args;
}			t_conv;

int		ft_printf(const char *s, ...);
void	ft_getwidth(t_conv *tc);
void	ft_getpadding(t_conv *tc);
void	ft_getprecision(t_conv *tc);

#endif
