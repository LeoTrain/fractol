/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:59:38 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:00:52 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	hook_handle_loop(void *param)
{
	t_errors		error;
	t_data			*data;

	data = (t_data *)param;
	if (data->needs_redraw == 1)
	{
		error = render_fractol(data);
		if (error != ERROR_NONE)
		{
			show_error(error);
			cleanup_mlx(data);
			exit(error);
		}
		data->needs_redraw = 0;
	}
	return (EXIT_SUCCESS);
}

int	hook_handle_mouse(int button, int x, int y, void *param)
{
	t_data			*data;
	t_complex		mouse_complex;

	data = (t_data *)param;
	if ((button == 4 || button == 5) && data->needs_redraw == 0)
	{
		pixel_to_complex(x, y, data, &mouse_complex);
		if (button == 4)
			data->fractal.zoom_level *= 1.1;
		else
			data->fractal.zoom_level /= 1.1;
		data->fractal.complex_center = mouse_complex;
		data->needs_redraw = 1;
	}
	return (EXIT_SUCCESS);
}

int	hook_handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC_KEY)
		close_all(data);
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
	{
		if (keycode == RIGHT_KEY)
			data->fractal.complex_center.real += 0.1;
		else
			data->fractal.complex_center.real -= 0.1;
		data->needs_redraw = 1;
	}
	else if (keycode == UP_KEY || keycode == DOWN_KEY)
	{
		if (keycode == UP_KEY)
			data->fractal.complex_center.imaginary += 0.1;
		else
			data->fractal.complex_center.imaginary -= 0.1;
		data->needs_redraw = 1;
	}
	return (EXIT_SUCCESS);
}
