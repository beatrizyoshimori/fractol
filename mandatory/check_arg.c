/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:37:10 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/28 14:51:38 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_message(void)
{
	ft_putstr_fd("\nWrong arguments!\n\nTo generate a fractal, you can ", 1);
	ft_putstr_fd("choose between:\n1. Mandelbrot\n2. Julia + complex ", 1);
	ft_putstr_fd("number between -2.0 and 2.0\n\nSo your", 1);
	ft_putstr_fd(" input should look something like this:\n", 1);
	ft_putstr_fd("./fractol Mandelbrot\n", 1);
	ft_putstr_fd("./fractol Julia -0.6782 0.3425\n\n", 1);
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	if (argc == 2 && ft_strncmp("Mandelbrot", argv[1], 10) == 0)
	{
		data->fractal_set = 'm';
		return (1);
	}
	else if (argc == 4 && ft_strncmp("Julia", argv[1], 5) == 0
		&& ft_atof(argv[2]) >= -2.0 && ft_atof(argv[2]) <= 2.0
		&& ft_atof(argv[3]) >= -2.0 && ft_atof(argv[3]) <= 2.0)
	{
		data->fractal_set = 'j';
		data->x_julia = ft_atof(argv[2]);
		data->y_julia = ft_atof(argv[3]);
		return (1);
	}
	error_message();
	return (0);
}
