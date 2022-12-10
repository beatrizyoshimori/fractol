/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:48:26 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/09 23:57:02 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (image->size_line * y + (image->bits_per_pixel / 8) * x);
	*(int *)pixel = color;
}

void	error_message(void)
{
	ft_putstr_fd("Wrong arguments!\nTry: ./fractol Mandelbrot\n", 1);
	return ;
}

int	check_arg(int argc, char *argv[])
{
	if (argc == 2)
		if (ft_strncmp("Mandelbrot", argv[1], 10) == 0)
			return (1);
	error_message();
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (check_arg(argc, argv))
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (1);
		data->ptr = mlx_init();
		if (!data->ptr)
		{
			free(data);
			return (1);
		}
		data->new_window = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fractol");
		if (!data->new_window)
		{
			mlx_destroy_display(data->ptr);
			free(data->ptr);
			free(data);
			return (1);
		}
		data->image.x_max = CX_MAX;
		data->image.x_min = CX_MIN;
		data->image.y_max = CY_MAX;
		data->image.y_min = CY_MIN;
		start_image(data);
		mlx_mouse_hook(data->new_window, zoom, data);
		mlx_hook(data->new_window, KeyPress, KeyPressMask, handle_keypress, data);
		mlx_hook(data->new_window, DestroyNotify, KeyPressMask, close_program, data);
		mlx_loop_hook(data->ptr, start_image, data);
		mlx_loop(data->ptr);
	}
	return (0);
}