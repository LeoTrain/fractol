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

static int	choose_iteration_logic(t_data *data, t_complex complex);
static t_errors	rendering_loop(t_data *data, int x, int y);

t_errors	render_fractol(t_data *data)
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
			error = rendering_loop(data, x, y);
			if (error != ERROR_NONE)
				return (error);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window,
		data->mlx.img.image, 0, 0);
	return (ERROR_NONE);
}

static t_errors	rendering_loop(t_data *data, int x, int y)
{
	t_complex	complex;
	int			iteration;
	int			color;

	complex = pixel_to_complex(x, y, &data->fractal, &data->size);
	iteration = choose_iteration_logic(data, complex);
	color = iteration_to_color(iteration, data->fractal.max_iterations);
	my_mlx_pixel_put(&data->mlx.img, x, y, color);
	return (ERROR_NONE);
}

static int	choose_iteration_logic(t_data *data, t_complex complex)
{
	if (data->fractal.type == MANDELBROT)
		return (mandelbrot_iterations(complex.real,
				complex.imaginary, data->fractal.max_iterations));
	else
		return (julia_iterations(complex,
				data->fractal.complex_julia, data->fractal.max_iterations));
}
