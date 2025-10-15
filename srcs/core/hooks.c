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
	if (data->needs_redraw == TRUE)
	{
		error = render_fractol(data);
		if (error != ERROR_NONE)
		{
			show_error(error);
			cleanup_mlx(data);
			exit(error);
		}
		data->needs_redraw = FALSE;
	}
	return (EXIT_SUCCESS);
}

int	hook_handle_mouse(int button, int x, int y, void *param)
{
	t_data			*data;
	t_complex		mouse_complex;

	data = (t_data *)param;
	if ( (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		&& data->needs_redraw == FALSE)
	{
		pixel_to_complex(x, y, data, &mouse_complex);
		if (button == MOUSE_SCROLL_UP)
			data->fractal.zoom_level *= ZOOM_FACTOR;
		else
			data->fractal.zoom_level /= ZOOM_FACTOR;
		data->fractal.complex_center = mouse_complex;
		data->needs_redraw = TRUE;
	}
	return (EXIT_SUCCESS);
}

int	hook_handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESC)
		close_all(data);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_RIGHT)
			data->fractal.complex_center.real += MOVEMENT_STEP;
		else
			data->fractal.complex_center.real -= MOVEMENT_STEP;
		data->needs_redraw = TRUE;
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		if (keycode == KEY_UP)
			data->fractal.complex_center.imaginary += MOVEMENT_STEP;
		else
			data->fractal.complex_center.imaginary -= MOVEMENT_STEP;
		data->needs_redraw = TRUE;
	}
	return (EXIT_SUCCESS);
}
