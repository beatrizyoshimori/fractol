/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:48:26 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/04 20:41:18 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	close_program(t_data *data)
{
	mlx_destroy_window(data->ptr, data->new_window);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	free(data);
	exit(0);
	return (0);
}

int	start_image(t_data *data)
{
	data->image.new_image = mlx_new_image(data->ptr, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.new_image, &data->image.bits_per_pixel, &data->image.size_line, &data->image.endian);
	mandelbrot(data);
	mlx_put_image_to_window(data->ptr, data->new_window, data->image.new_image, 0, 0);
	mlx_destroy_image(data->ptr, data->image.new_image);
	return (0);
}

int	zoom(int keysys, t_data *data)
{
	printf("\n%p\n", data);
	if (keysys == 4)
	{
		printf("\nk\n");
		
		printf("\n%p\n", data->image.new_image);
		data->image.x_max -= 0.1;
		printf("\n1\n");
		data->image.x_min += 0.1;
		data->image.y_max -= 0.1;
		data->image.y_min += 0.1;
	}
	else
		return (0);
	start_image(data);
	return (0);
}

int	handle_keypress(int keysim, t_data *data)
{
	if (keysim == XK_Escape)
		close_program(data);
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

	data = malloc(sizeof(t_data));
	data->ptr = mlx_init();
	data->new_window = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fractol");
	data->image.x_max = 2.0;
	data->image.x_min = -2.0;
	data->image.y_max = 2.0;
	data->image.y_min = -2.0;
	start_image(data);
	printf("\n%p\n", data);
	mlx_mouse_hook(data->new_window, zoom, data);
	mlx_hook(data->new_window, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->new_window, DestroyNotify, KeyPressMask, close_program, data);
	mlx_loop(data->ptr);
	return (0);
}