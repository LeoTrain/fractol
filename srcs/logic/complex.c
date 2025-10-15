/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:33:11 by leberton          #+#    #+#             */
/*   Updated: 2025/09/06 17:33:12 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static double	normalize_coordinate(double pixel_coord, double max_dimension)
{
	return (pixel_coord / max_dimension - COORDINATE_CENTER_OFFSET);
}

static double	calculate_complex_real(int pixel_x, t_data *fractal_data,
								double zoom_factor)
{
	double		normalized_x;
	double		shift_x;

	normalized_x = normalize_coordinate((double)pixel_x,
			fractal_data->size.width);
	shift_x = fractal_data->shift.x * zoom_factor / BASE_VIEW_FACTOR;
	return (fractal_data->fractal.complex_center.real
		+ (normalized_x * zoom_factor + shift_x));
}

static double	calculate_complex_imaginary(int pixel_y, t_data *fractal_data,
								double zoom_factor)
{
	double		normalized_y;
	double		shift_y;

	normalized_y = normalize_coordinate((double)pixel_y,
			fractal_data->size.height);
	shift_y = fractal_data->shift.y * zoom_factor / BASE_VIEW_FACTOR;
	return (fractal_data->fractal.complex_center.imaginary
		+ (normalized_y * zoom_factor + shift_y));
}

t_errors	pixel_to_complex(int x, int y, t_data *data, t_complex *complex)
{
	double	zoom_factor;

	zoom_factor = BASE_VIEW_FACTOR / data->fractal.zoom_level;
	complex->real = calculate_complex_real(x, data, zoom_factor);
	complex->imaginary = calculate_complex_imaginary(y, data, zoom_factor);
	return (ERROR_NONE);
}
