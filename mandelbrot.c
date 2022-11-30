/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:07:54 by byoshimo          #+#    #+#             */
/*   Updated: 2022/11/30 02:08:11 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	pixel_width = (CX_MAX - CX_MIN) / WIDTH;
	pixel_height = (CY_MAX - CY_MIN) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		cy = CY_MIN + y * pixel_height;
		x = 0;
		while (x < WIDTH)
		{
			cx = CX_MIN + x * pixel_width;
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
			if (count == MAX_ITER)
				image_pixel_put(&data->image, x, y, 0x00000000);
			else
				image_pixel_put(&data->image, x, y, 0x00ABCDEF * count);
			x++;
		}
		y++;
	}
}
