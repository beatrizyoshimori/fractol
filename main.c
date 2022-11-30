/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:48:26 by byoshimo          #+#    #+#             */
/*   Updated: 2022/11/30 02:24:49 by byoshimo         ###   ########.fr       */
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

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_keypress(int keysim, t_data *data)
{
	if (keysim == XK_Escape)
	{
		//mlx_destroy_window(data->ptr, data->new_window);
		close_program(data);
	}
	return (0);
}

// int	handle_keyrelease(int keysim, t_data *data)
// {
// 	if (keysim == XK_Escape)
// 		mlx_destroy_window(data->ptr, data->new_window);
// 	return (0);
// }

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (image->size_line * y + (image->bits_per_pixel / 8) * x);
	*(int *)pixel = color;
}

int	main(void)
{
	t_data	*data;
	//int		color;

	data = malloc(sizeof(t_data));
	data->ptr = mlx_init();
	data->new_window = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fractol");
	data->image.new_image = mlx_new_image(data->ptr, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.new_image, &data->image.bits_per_pixel, &data->image.size_line, &data->image.endian);
	mandelbrot(data);
	mlx_put_image_to_window(data->ptr, data->new_window, data->image.new_image, 0, 0);
	mlx_loop_hook(data->ptr, &handle_no_event, &data);
	mlx_hook(data->new_window, KeyPress, KeyPressMask, &handle_keypress, &data);
	//mlx_hook(data->new_window, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_hook(data->new_window, DestroyNotify, NoEventMask, &close_program, &data);
	mlx_loop(data->ptr);
	// mlx_destroy_window(data->ptr, data->new_window);
	// mlx_destroy_display(data->ptr);
	// free(data->ptr);
	// free(data);
	// exit(0);
	return (0);
}