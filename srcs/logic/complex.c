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

t_errors	pixel_to_complex(int x, int y, t_data *data, t_complex *complex)
{
	t_complex	base_complex;
	double		view_factor;
	double		shift_offset_x;
	double		shift_offset_y;

	base_complex = data->fractal.complex_center;
	view_factor = BASE_VIEW_FACTOR / data->fractal.zoom_level;
	shift_offset_x = data->shift.x * view_factor / BASE_VIEW_FACTOR;
	shift_offset_y = data->shift.y * view_factor / BASE_VIEW_FACTOR;
	complex->real = base_complex.real + (
			((double)x / data->size.width - COORDINATE_CENTER_OFFSET) * view_factor) + shift_offset_x;
	complex->imaginary = base_complex.imaginary - (
			((double)y / data->size.height - COORDINATE_CENTER_OFFSET) * view_factor) + shift_offset_y;
	return (ERROR_NONE);
}
