/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:48:08 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/20 19:06:25 by byoshimo         ###   ########.fr       */
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

static void	change_color(t_data *data)
{
	if (data->color == 0x00010107)
		data->color = 0x00000109;
	else if (data->color == 0x00000109)
		data->color = 0x00000500;
	else if (data->color == 0x00000500)
		data->color = 0x00050100;
	else if (data->color == 0x00050100)
		data->color = 0x00010107;
}

int	mouse_event(int keysys, int x, int y, t_data *data)
{
	double	dx;
	double	dy;

	dx = (data->image.x_max - data->image.x_min) * 0.1;
	dy = (data->image.y_max - data->image.y_min) * 0.1;
	if (keysys == 1)
		change_color(data);
	else if (keysys == 4)
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
	if (keysim == ARROW_LEFT)
	{
		data->image.x_max -= dx;
		data->image.x_min -= dx;
	}
	else if (keysim == ARROW_RIGHT)
	{
		data->image.x_max += dx;
		data->image.x_min += dx;
	}
	else if (keysim == ARROW_UP)
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
	if (keysim == ESC)
		close_program(data);
	else if (keysim == ARROW_LEFT || keysim == ARROW_RIGHT
		|| keysim == ARROW_UP || keysim == ARROW_DOWN)
		move_arrow(keysim, data);
	else if (keysim == LETTER_R)
		first_image(data);
	return (0);
}
