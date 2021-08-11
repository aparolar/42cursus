/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:21:07 by aparolar          #+#    #+#             */
/*   Updated: 2021/07/30 13:29:05 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

void	new_image(t_data *img, t_vars *vars, int width, int height)
{
		img->img = mlx_new_image(vars->mlx, width, height);
		img->addr = mlx_get_data_addr(
						img->img,
						&img->bits_per_pixel,
						&img->line_length,
						&img->endian);
}
