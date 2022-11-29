/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:48:26 by byoshimo          #+#    #+#             */
/*   Updated: 2022/11/26 22:36:44 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_keypress(int keysim, t_data *data)
{
	if (keysim == XK_Escape)
		mlx_destroy_window(data->ptr, data->new_window);
	return (0);
}

// int	handle_keyrelease(int keysim, t_data *data)
// {
// 	if (keysim == XK_Escape)
// 		mlx_destroy_window(data->ptr, data->new_window);
// 	return (0);
// }

int	clean_exit(t_data *data)
{
	exit(0);
	return (0);
}

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (image->size_line * y + (image->bits_per_pixel / 8) * x);
	*(int *)pixel = color;
}

int	main(void)
{
	t_data	*data;
	int		x;
	int		y;
	double	z_real;
	double	z_imaginary;
	double	z_temp;
	double	cxmin;
	double	cxmax;
	double	cymin;
	double	cymax;
	double	cx;
	double	cy;
	double	pixel_width;
	double	pixel_height;
	int		count;
	//int		color;

	data = malloc(sizeof(t_data));
	data->ptr = mlx_init();
	data->new_window = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fractol");
	data->image.new_image = mlx_new_image(data->ptr, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.new_image, &data->image.bits_per_pixel, &data->image.size_line, &data->image.endian);
	cxmin = -2.5;
	cxmax = 1.5;
	cymin = -2.0;
	cymax = 2.0;
	pixel_width = (cxmax - cxmin) / WIDTH;
	pixel_height = (cymax - cymin) / HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		cy = cymin + y * pixel_height;
		x = 0;
		while (x < WIDTH)
		{
			cx = cxmin + x * pixel_width;
			count = 0;
			z_real = 0;
			z_imaginary = 0;
			while (z_real * z_real + z_imaginary * z_imaginary < 4 && count < 500)
			{
				z_temp = z_real * z_real - z_imaginary * z_imaginary + cx;
				z_imaginary = 2 * z_real * z_imaginary + cy;
				z_real = z_temp;
				count++;
			}
			if (count == 500)
				image_pixel_put(&data->image, x, y, 0x00000000);
			else
				image_pixel_put(&data->image, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->ptr, data->new_window, data->image.new_image, 0, 0);
	mlx_loop_hook(data->ptr, &handle_no_event, &data);
	mlx_hook(data->new_window, KeyPress, KeyPressMask, &handle_keypress, &data);
	//mlx_hook(data->new_window, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_hook(data->new_window, DestroyNotify, NoEventMask, &clean_exit, &data);
	mlx_loop(data->ptr);
	//mlx_destroy_window(data->ptr, data->new_window);
	mlx_destroy_display(data->ptr);
	free(data);
}