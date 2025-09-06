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

t_complex	pixel_to_complex(int x, int y, t_fractal *fractal, t_size *size)
{
	t_complex	complex;
	t_complex	base_complex;
	double		view_factor;

	base_complex = fractal->complex_center;
	view_factor = 4.0 / fractal->zoom_level;
	complex.real = base_complex.real + (((double)x / size->width - 0.5)
			* view_factor);
	complex.imaginary = base_complex.imaginary - (
			((double)y / size->height - 0.5) * view_factor);
	return (complex);
}
