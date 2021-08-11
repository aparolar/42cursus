/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmkeycodes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:42:42 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/05 13:06:22 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* keycode */
# ifdef __linux
#  define KEY_LEFT        65361
#  define KEY_RIGHT       65363
#  define KEY_DOWN        65364
#  define KEY_UP          65362
#  define KEY_A           97
#  define KEY_D           100
#  define KEY_S           115
#  define KEY_W           119
#  define KEY_SCROLLUP    5
#  define KEY_SCROLLDOWN  4
#  define KEY_SCROLLLEFT  6
#  define KEY_SCROLLRIGHT 7
#  define KEY_ESC         65307
#  define KEY_PLUS        0x002b
#  define KEY_MINUS       0x002d
# else
#  define KEY_LEFT        123
#  define KEY_RIGHT       124
#  define KEY_DOWN        125
#  define KEY_UP          126
#  define KEY_A           0
#  define KEY_D           2
#  define KEY_S           1
#  define KEY_W           13
#  define KEY_SCROLLUP    5
#  define KEY_SCROLLDOWN  4
#  define KEY_SCROLLLEFT  6
#  define KEY_SCROLLRIGHT 7
#  define KEY_ESC         53
# endif
