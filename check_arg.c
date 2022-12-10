/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:37:10 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/10 19:17:50 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
