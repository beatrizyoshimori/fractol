/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:48:08 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/17 17:15:33 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	follow_mouse(int x, int y, t_data *data)
{
	double	dx;
	double	dy;

	dx = (data->image.x_max - data->image.x_min) / WIDTH * (x - WIDTH / 2);
	dy = (data->image.y_max - data->image.y_min) / HEIGHT * (y - WIDTH / 2);
	data->image.x_max += dx;
	data->image.x_min += dx;
	data->image.y_max += dy;
	data->image.y_min += dy;
}

static void	change_color(int keysim, t_data *data)
{
	if (keysim == XK_1)
		data->color = 0x00000500;
	else if (keysim == XK_2)
		data->color = 0x00050100;
	else if (keysim == XK_3)
		data->color = 0x0500F001;
	// else if (keysim == XK_4)
	else if (keysim == XK_5)
		data->color = 0x00000109;
}

int	zoom(int keysys, int x, int y, t_data *data)
{
	double	dx;
	double	dy;

	dx = (data->image.x_max - data->image.x_min) * 0.1;
	dy = (data->image.y_max - data->image.y_min) * 0.1;
	if (keysys == 4)
	{
		data->image.x_max -= dx;
		data->image.x_min += dx;
		data->image.y_max -= dy;
		data->image.y_min += dy;
		follow_mouse(x, y, data);
	}
	else if (keysys == 5)
	{
		data->image.x_max += dx;
		data->image.x_min -= dx;
		data->image.y_max += dy;
		data->image.y_min -= dy;
		follow_mouse(x, y, data);
	}
	return (0);
}

static void	move_arrow(int keysim, t_data *data)
{
	double	dx;
	double	dy;

	dx = (data->image.x_max - data->image.x_min) / 10;
	dy = (data->image.y_max - data->image.y_min) / 10;
	if (keysim == XK_Left)
	{
		data->image.x_max -= dx;
		data->image.x_min -= dx;
	}
	else if (keysim == XK_Right)
	{
		data->image.x_max += dx;
		data->image.x_min += dx;
	}
	else if (keysim == XK_Up)
	{
		data->image.y_max -= dy;
		data->image.y_min -= dy;
	}
	else
	{
		data->image.y_max += dy;
		data->image.y_min += dy;
	}
}

int	handle_keypress(int keysim, t_data *data)
{
	if (keysim == XK_Escape)
		close_program(data);
	else if (keysim == XK_Left || keysim == XK_Right
		|| keysim == XK_Up || keysim == XK_Down)
		move_arrow(keysim, data);
	else if (keysim == XK_1 || keysim == XK_2 || keysim == XK_3
		|| keysim == XK_4 || keysim == XK_5)
		change_color(keysim, data);
	return (0);
}
