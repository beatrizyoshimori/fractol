/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:33:46 by byoshimo          #+#    #+#             */
/*   Updated: 2022/11/22 03:15:32 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct	s_image
{
	void	*new_image;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct	s_data
{
	void	*ptr;
	void	*new_window;
	t_image	image;
}	t_data;

#endif