/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:33:17 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/21 18:33:27 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	error_message(void)
{
	ft_putstr_fd("\nWrong arguments!\n\nTo generate a fractal, you can ", 1);
	ft_putstr_fd("choose between:\n1. Mandelbrot\n2. Julia + complex ", 1);
	ft_putstr_fd("number between -2.0 and 2.0\n3. BurningShip\n\nSo your", 1);
	ft_putstr_fd(" input should look something like this:\n", 1);
	ft_putstr_fd("./fractol Mandelbrot\n", 1);
	ft_putstr_fd("./fractol Julia -0.6782 0.3425\n", 1);
	ft_putstr_fd("./fractol BurningShip\n\n", 1);
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	if (argc == 2)
	{
		if (ft_strncmp("Mandelbrot", argv[1], 10) == 0)
		{
			data->fractal_set = 'm';
			return (1);
		}
		else if (ft_strncmp("BurningShip", argv[1], 11) == 0)
		{
			data->fractal_set = 'b';
			return (1);
		}
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
