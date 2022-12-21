/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:14:49 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/21 18:15:55 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	else if (keysim == KEY_R)
		first_image(data);
	else if (keysim == KEY_SPACE && data->fractal_set == 'j')
		data->julia_set_image = 1;
	return (0);
}
