/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:08:04 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/21 19:29:02 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_event(int keysys, int x, int y, t_data *data)
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
	else if (keysys == 5)
	{
		data->image.x_max += dx;
		data->image.x_min -= dx;
		data->image.y_max += dy;
		data->image.y_min -= dy;
	}
	x = y;
	return (0);
}

int	mouse_julia(int x, int y, t_data *data)
{
	if (data->fractal_set == 'j' && data->julia_set_image == 0)
	{
		data->x_julia = (data->image.x_max - data->image.x_min)
			/ WIDTH * (x - WIDTH / 2);
		data->y_julia = (data->image.y_max - data->image.y_min)
			/ HEIGHT * (y - HEIGHT / 2);
	}
	return (0);
}
