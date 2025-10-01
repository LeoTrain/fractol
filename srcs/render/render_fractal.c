/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:42:40 by leberton          #+#    #+#             */
/*   Updated: 2025/09/06 17:42:43 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_errors	choose_iteration_logic(t_data *data, t_complex complex,
									   int *iteration);
static t_errors	rendering_logic(t_data *data, int x, int y);
static t_errors	rendering_loop(t_data *data);

t_errors	render_fractol(t_data *data)
{
	t_errors	error;

	error = rendering_loop(data);
	if (error != ERROR_NONE)
		return (error);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window,
		data->mlx.img.image, 0, 0);
	return (ERROR_NONE);
}

static t_errors	rendering_loop(t_data *data)
{
	int			x;
	int			y;
	t_errors	error;

	y = 0;
	while (y < data->size.height)
	{
		x = 0;
		while (x < data->size.width)
		{
			error = rendering_logic(data, x, y);
			if (error != ERROR_NONE)
				return (error);
			x++;
		}
		y++;
	}
	return (ERROR_NONE);
}

static t_errors	rendering_logic(t_data *data, int x, int y)
{
	t_errors	error;
	t_complex	complex;
	int			iteration;
	int			color;

	error = pixel_to_complex(x, y, data, &complex);
	if (error != ERROR_NONE)
		return (error);
	error = choose_iteration_logic(data, complex, &iteration);
	if (error != ERROR_NONE)
		return (error);
	error = iteration_to_color( iteration, data->fractal.max_iterations, &color);
	if (error != ERROR_NONE)
		return (error);
	error = my_mlx_pixel_put(&data->mlx.img, x, y, color);
	if (error != ERROR_NONE)
		return (error);
	return (ERROR_NONE);
}

static t_errors	choose_iteration_logic(t_data *data, t_complex complex,
								  int *iteration)
{
	if (data->fractal.type == MANDELBROT)
	{
		*iteration = mandelbrot_iterations(complex,
									 	data->fractal.max_iterations);
		return (ERROR_NONE);
	}
	else if (data->fractal.type == JULIA)
	{
		*iteration = julia_iterations(complex, data->fractal.complex_julia,
									data->fractal.max_iterations);
		return (ERROR_NONE);
	}
	return (ERROR_UNKNOW);
}
