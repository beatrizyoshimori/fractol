/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:48:08 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/09 01:51:47 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int keysys, int x, int y, t_data *data)
{
	double	dx;
	double	dy;
	int	mouse_x_pos;
	int	mouse_y_pos;

	mlx_mouse_get_pos(data->ptr, data->new_window, &mouse_x_pos, &mouse_y_pos);
	printf("\nx:%d\n", mouse_x_pos);
	printf("\ny:%d\n", mouse_y_pos);
	dx = (data->image.x_max - data->image.x_min) / 10;
	dy = (data->image.y_max - data->image.y_min) / 10;
	x = y;
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
