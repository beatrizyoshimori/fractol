/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:48:08 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/13 20:51:09 by byoshimo         ###   ########.fr       */
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
	}
	if (keysys == 5)
	{
		data->image.x_max += dx;
		data->image.x_min -= dx;
		data->image.y_max += dy;
		data->image.y_min -= dy;
	}
	follow_mouse(x, y, data);
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
	return (0);
}
