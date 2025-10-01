/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:31:12 by leberton          #+#    #+#             */
/*   Updated: 2025/09/06 17:31:13 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_errors	init_mlx_img(t_data *data);
static int		handle_keypress(int keycode, void *param);
static int		handle_mouse(int button, int x, int y, void *param);
static int		loop_loop(void *param);

t_errors	init_minitlibx(t_data *data)
{
	t_errors	error;

	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		return (ERROR_MLX_DISPLAY);
	data->mlx.window = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "Fractol");
	if (data->mlx.window == NULL)
	{
		mlx_destroy_display(data->mlx.mlx);
		return (ERROR_MLX_WINDOW);
	}
	data->size.width = WIDTH;
	data->size.height = HEIGHT;
	error = init_mlx_img(data);
	if (error != ERROR_NONE)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.window);
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		return (error);
	}
	mlx_hook(data->mlx.window, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->mlx.window, 17, 0, close_all, data);
	mlx_mouse_hook(data->mlx.window, handle_mouse, data);
	mlx_loop_hook(data->mlx.mlx, loop_loop, data);
	return (ERROR_NONE);
}

static t_errors	init_mlx_img(t_data *data)
{
	data->mlx.img.image = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	if (data->mlx.img.image == NULL)
		return (ERROR_MLX_IMG);
	data->mlx.img.address = mlx_get_data_addr(data->mlx.img.image,
			&data->mlx.img.bit_per_pixel, &data->mlx.img.line_length,
			&data->mlx.img.endian);
	if (data->mlx.img.address == NULL)
	{
		mlx_destroy_image(data->mlx.mlx, data->mlx.img.image);
		return (ERROR_MLX_IMG_ADDRESS);
	}
	return (ERROR_NONE);
}

static int	loop_loop(void *param)
{
	t_errors		error;
	t_data			*data;

	data = (t_data *)param;
	if (data->needs_redraw == 1)
	{
		error = render_fractol(data);
		if (error != ERROR_NONE)
		{
			cleanup_mlx(data);
			exit(error);
		}
		data->needs_redraw = 0;
	}
	return (EXIT_SUCCESS);
}

static int	handle_mouse(int button, int x, int y, void *param)
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

static int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC_KEY)
		close_all(keycode, data);
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
