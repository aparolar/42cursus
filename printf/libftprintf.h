/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:57:53 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/11 12:46:12 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdio.h> //eliminar al acabar

/*
**  Defines
*/

# define TYPES "cspdiuxX%"

/*
**  structs;
**
*/

typedef struct s_printf
{
	char	*str;
	va_list	args;
	int		flag_minus;
	int		flag_zero;
	int		width;
	int		dot;
	int		precision;
	int		flag_pre_va;
	int		num_m;
	char	type;
	int		itsok;
}			t_printf;

int		ft_printf(const char *s, ...);
void	ft_reset_t_printf(t_printf *tc);
void	ft_padding(int width, char c);
int		ft_preparse(t_printf *tc);
int		ft_check_arg(t_printf *tc);
int		ft_parsebypass(t_printf *tc);
void	ft_parse_c(t_printf *tc);
void	ft_parse_s(t_printf *tc);
void	ft_parse_p(t_printf *tc);
void	ft_parse_d(t_printf *tc);
void	ft_parse_i(t_printf *tc);
void	ft_parse_u(t_printf *tc);
void	ft_parse_x(t_printf	*tc);
void	ft_parse_ux(t_printf *tc);
void	ft_parse_perback(t_printf *tc);

#endif
