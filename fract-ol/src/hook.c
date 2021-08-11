/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:55:05 by aparolar          #+#    #+#             */
/*   Updated: 2021/08/11 11:42:04 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract-ol.h"

int	main_key_hook(int keycode, t_render *render)
{
	printf("Keycode = [ %5d ]\n", keycode);
	if (keycode == KEY_ESC)
	{
		free_all(render);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_DOWN)
		render->posy -= 0.10f / render->zoom;
	if (keycode == KEY_UP)
		render->posy += 0.10f / render->zoom;
	if (keycode == KEY_LEFT)
		render->posx += 0.10f / render->zoom;
	if (keycode == KEY_RIGHT)
		render->posx -= 0.10f / render->zoom;
	if (keycode == KEY_PLUS)
		render->zoom *= 1.25f;
	if (keycode == KEY_MINUS && render->zoom / 1.25f >= 1)
		render->zoom /= 1.25f;
	printf("Keyboard x = %f y = %f\n", render->posx, render->posy);
	render_next_frame(render);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_render *render)
{
	printf("mouse x = %d y = %d\n", x, y);
	if (button == 4)
	{
		render->zoom *= 1.25f;
		render->posx = (2. / render->w) * (x - render->w / 2.);// / render->zoom;//(1.0 / render->w / 2));// / (float)render->w;
		render->posy = (2. / render->h) * (y - render->h / 2.);// / render->zoom;//(1.0 / render->h / 2));// / (float)render->h;
//		render->posx = (x - render->w / 2.) * 0.0010;// / render->zoom;//(1.0 / render->w / 2));// / (float)render->w;
//		render->posy = (y - render->h / 2.) * 0.0010;// / render->zoom;//(1.0 / render->h / 2));// / (float)render->h;
		render_next_frame(render);
	}
	else if (button == 5)
	{
		render->zoom /= 1.25f;
		render->posx = (x - (render->w / 2)) / render->zoom;
		render->posy = (y - (render->h / 2)) / render->zoom;
		render_next_frame(render);
	}
	printf("Mouse x = %f y = %f\n", render->posx, render->posy);
	return (0);
}

int render_next_frame(void *render)
{
	t_render	*tr;
	int	x;
	int	y;

	tr = (t_render *)render;
	mlx_do_sync(tr->vars.mlx);
	y = 0;
	while (y < tr->h)
	{
			x = 0;
			while (x < tr->w)
			{
				if (tr->type == 1)
					julia(render, x, y);
				else
					mandelbrot(render, x, y);
				x++;
			}
			y++;
	}
	mlx_put_image_to_window(tr->vars.mlx, tr->vars.win, tr->img.img, 0, 0);
	return (0);
}
