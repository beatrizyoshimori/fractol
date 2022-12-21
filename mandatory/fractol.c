/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:48:26 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/21 19:37:53 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	start_image(t_data *data)
{
	data->image.new_image = mlx_new_image(data->ptr, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.new_image,
			&data->image.bpp, &data->image.size_line, &data->image.endian);
	if (data->fractal_set == 'm')
		mandelbrot(data);
	else if (data->fractal_set == 'j')
		julia(data);
	mlx_put_image_to_window(data->ptr, data->window,
		data->image.new_image, 0, 0);
	mlx_destroy_image(data->ptr, data->image.new_image);
	return (0);
}

void	first_image(t_data *data)
{
	data->image.x_max = CX_MAX;
	data->image.x_min = CX_MIN;
	data->image.y_max = CY_MAX;
	data->image.y_min = CY_MIN;
	data->color = 0x00000109;
	data->julia_set_image = 0;
	start_image(data);
}

static int	start_window(t_data *data)
{
	data->ptr = mlx_init();
	if (!data->ptr)
		return (free(data), 1);
	data->window = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fractol");
	if (!data->window)
	{
		mlx_destroy_display(data->ptr);
		free(data->ptr);
		free(data);
		return (1);
	}
	first_image(data);
	mlx_mouse_hook(data->window, mouse_event, data);
	mlx_hook(data->window, 6, 1L << 6, mouse_julia, data);
	mlx_hook(data->window, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->window, 17, 1L << 0, close_program, data);
	mlx_loop_hook(data->ptr, start_image, data);
	mlx_loop(data->ptr);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 2);
	if (!data)
		return (1);
	if (check_arg(argc, argv, data))
		start_window(data);
	else
		free(data);
	return (0);
}
