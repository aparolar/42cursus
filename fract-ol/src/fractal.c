/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:30:02 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/11 11:24:25 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

void    julia(t_render *tr, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			count;
	double		tx;
	
	c.real = -0.74f;
	c.imag = 0.27015f;
	z.real = 1.5 * (x - tr->w / 2);
	z.real = z.real / (0.4 * tr->zoom * tr->w);
	z.real += tr->posx;// + (tr->posx / tr->zoom);
	z.imag = (y - tr->h / 2);
	z.imag = z.imag / (0.4 * tr->zoom * tr->h);
	z.imag += tr->posy;// + (tr->posy / tr->zoom);
	count = 0;
	while ((z.real * z.real + z.imag * z.imag < 4.0f) && count < 300)
	{
		tx = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tx;
		count++;
	}
	mlx_pixel_put_ex(&tr->img, x, y, create_color(count));
	//if ((x == 0 && y == 0) || (x == tr->w -1 && y == tr->h -1))
	//	printf("fractal x = %d y = %d , z.real = %f z.imag = %f\n", x, y, z.real, z.imag);
}

void    mandelbrot(t_render *tr, int x, int y)
{
	t_complex z;
	t_complex c;
	int count;
	float       tx;
	
	c.real = -0.9f;
	c.imag = 0.27015f;
	c.real = 1.5 * (x - tr->w / 2);
	c.real = c.real / (0.4 * tr->zoom * tr->w);
	c.real += tr->posx + (tr->posx / tr->zoom);
	c.imag = (y - tr->h / 2);
	c.imag = c.imag / (0.4 * tr->zoom * tr->h);
	c.imag += tr->posy + (tr->posy / tr->zoom);
	z.real = 0;
	z.imag = 0;
	count = 0;
	while ((z.real * z.real + z.imag * z.imag < 4.0f) && count < 50)
	{
		tx = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tx;
		count++;
	}
	mlx_pixel_put_ex(&tr->img, x, y, create_color(count));
}