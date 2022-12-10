/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:48:08 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/09 22:07:29 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int keysys, int x, int y, t_data *data)
{
	double	dx_max;
	double	dx_min;
	double	dy_max;
	double	dy_min;

	dx_max = (data->image.x_max - ((data->image.x_max - data->image.x_min) * x / WIDTH));
	dy_max = (data->image.y_max - ((data->image.y_max - data->image.y_min) * y / HEIGHT));
	dx_min = (((data->image.x_max - data->image.x_min) * x / WIDTH) - data->image.x_min);
	dy_min = (((data->image.y_max - data->image.y_min) * y / HEIGHT) - data->image.y_min);
	// dx = (data->image.x_max - data->image.x_min) / 10;
	// dy = (data->image.y_max - data->image.y_min) / 10;
	printf("\n%d\n", y);
	if (keysys == 4)
	{
		data->image.x_max -= dx_min * 0.2;
		data->image.x_min += dx_max * 0.2;
		data->image.y_max -= dy_min * 0.2;
		data->image.y_min += dy_max * 0.2;
	}
	if (keysys == 5)
	{
		data->image.x_max += dx_min * 0.2;
		data->image.x_min -= dx_max * 0.2;
		data->image.y_max += dy_min * 0.2;
		data->image.y_min -= dy_max * 0.2;
	}
	return (0);
}

static void	move_arrow(int keysim, t_data *data)
{
	double dx;
	double dy;

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
	else if (keysim == XK_Left || keysim == XK_Right || 
				keysim == XK_Up || keysim == XK_Down)
		move_arrow(keysim, data);
	return (0);
}
