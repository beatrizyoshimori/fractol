/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:48:08 by byoshimo          #+#    #+#             */
/*   Updated: 2022/12/21 18:16:17 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keysim, t_data *data)
{
	if (keysim == ESC)
		close_program(data);
	else if (keysim == KEY_R)
		first_image(data);
	else if (keysim == KEY_SPACE && data->fractal_set == 'j')
		data->julia_set_image = 1;
	return (0);
}
