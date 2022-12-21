/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:17:18 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/21 18:30:20 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 200
# define CX_MAX 2.0
# define CX_MIN -2.0
# define CY_MAX 2.0
# define CY_MIN -2.0
# define ESC 65307
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define KEY_R 114
# define KEY_SPACE 32

typedef struct s_image
{
	void	*new_image;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
}	t_image;

typedef struct s_data
{
	void	*ptr;
	void	*window;
	t_image	image;
	char	fractal_set;
	int		color;
	double	x_julia;
	double	y_julia;
	int		julia_set_image;
}	t_data;

void	mandelbrot(t_data *data);
void	julia(t_data *data);
void	burning_ship(t_data *data);
int		mouse_event(int keysys, int x, int y, t_data *data);
int		mouse_julia(int x, int y, t_data *data);
int		handle_keypress(int keysim, t_data *data);
void	image_pixel_put(t_image *image, int x, int y, int color);
int		close_program(t_data *data);
double	ft_atof(const char *nptr);
int		start_image(t_data *data);
void	first_image(t_data *data);
int		check_arg(int argc, char *argv[], t_data *data);

#endif