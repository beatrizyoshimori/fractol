/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:07:54 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/01 22:34:08 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	make_color(int i)
{
	int	color;

	if (i == MAX_ITER)
		color = 0x00000000;
	else if (i % 10 == 0)
		color = 0x005984A5;
	else if (i % 10 == 1)
		color = 0x00243E52;
	else if (i % 10 == 2)
		color = 0x00A7C3DA;
	else if (i % 10 == 3)
		color = 0x00A3A8DE;
	else if (i % 10 == 4)
		color = 0x005D67DA;
	else if (i % 10 == 5)
		color = 0x009FA3D4;
	else if (i % 10 == 6)
		color = 0x00575B91;
	else if (i % 10 == 7)
		color = 0x00856CBF;
	else if (i % 10 == 8)
		color = 0x00897CA5;
	else
		color = 0x004B5EE4;
	return (color);
}

void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	xz;
	double	yz;
	double	z_temp;
	double	cx;
	double	cy;
	int		count;
	double	pixel_width;
	double	pixel_height;
	int		color;

	pixel_width = (data->image.x_max - data->image.x_min) / WIDTH;
	pixel_height = (data->image.y_max - data->image.y_min) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		cy = data->image.y_min + y * pixel_height;
		x = 0;
		while (x < WIDTH)
		{
			cx = data->image.x_min + x * pixel_width;
			count = 0;
			xz = 0;
			yz = 0;
			while (xz * xz + yz * yz < 4 && count < MAX_ITER)
			{
				z_temp = xz * xz - yz * yz + cx;
				yz = 2 * xz * yz + cy;
				xz = z_temp;
				count++;
			}
			color = make_color(count);
			image_pixel_put(&data->image, x, y, color);
			x++;
		}
		y++;
	}
}
