/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:32:35 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/21 18:32:52 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (image->size_line * y + (image->bpp / 8) * x);
	*(int *)pixel = color;
}

int	close_program(t_data *data)
{
	mlx_destroy_window(data->ptr, data->window);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	free(data);
	exit(0);
	return (0);
}

double	ft_atof(const char *nptr)
{
	int		i;
	int		sign;
	double	num;
	double	power;

	i = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	num = 0.0;
	power = 1.0;
	while (ft_isdigit(nptr[i]) == 1)
		num = num * 10 + (nptr[i++] - 48);
	if (nptr[i] == '.')
		i++;
	while (ft_isdigit(nptr[i]) == 1)
	{
		num = num * 10 + (nptr[i++] - 48);
		power *= 10;
	}
	return (num / power * sign);
}
