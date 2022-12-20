/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:46:55 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/20 12:36:47 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_burning_ship(double cx, double cy, t_data *data)
{
	int		iteration;
	double	xz;
	double	yz;
	double	z_temp;

	iteration = 0;
	xz = 0;
	yz = 0;
	while (xz * xz + yz * yz < 4 && iteration < MAX_ITER)
	{
		z_temp = xz * xz - yz * yz + cx;
		yz = fabs(2 * xz * yz) + cy;
		xz = z_temp;
		iteration++;
	}
	if (iteration == MAX_ITER)
		return (0x00000000);
	else
		return (data->color * iteration * iteration);
}

void	burning_ship(t_data *data)
{
	int		x;
	int		y;
	double	cx;
	double	cy;

	y = 0;
	while (y < HEIGHT)
	{
		cy = data->image.y_min + y
			* (data->image.y_max - data->image.y_min) / HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			cx = data->image.x_min + x
				* (data->image.x_max - data->image.x_min) / WIDTH;
			image_pixel_put(&data->image, x, y, set_burning_ship(cx, cy, data));
			x++;
		}
		y++;
	}
}
