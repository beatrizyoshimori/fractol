/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:33:46 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/13 23:28:50 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>


# include <stdio.h>



# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 300
# define CX_MAX 2.0
# define CX_MIN -2.0
# define CY_MAX 2.0
# define CY_MIN -2.0

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
}	t_data;

void	mandelbrot(t_data *data);
int		zoom(int keysys, int x, int y, t_data *data);
int		handle_keypress(int keysim, t_data *data);
int		close_program(t_data *data);
int		start_image(t_data *data);
void	image_pixel_put(t_image *image, int x, int y, int color);
void	error_message(void);
int		check_arg(int argc, char *argv[]);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif