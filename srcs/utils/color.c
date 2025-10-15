/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:05:02 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:05:03 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	create_trgb(int t, int r, int g, int b);

t_errors	iteration_to_color(int iteration, int iteration_max, int *color)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iteration < iteration_max)
	{
		t = (double)iteration / iteration_max;
		t = t * t * (SMOOTHING_COEFF_A - SMOOTHING_COEFF_B * t);
		r = (int)(RGB_MAX_VALUE * pow(t, GAMMA_RED));
		g = (int)(RGB_MAX_VALUE * pow(t, GAMMA_GREEN));
		b = (int)(RGB_MAX_VALUE * t);
		*color = create_trgb(ALPHA_TRANSPARENT, r, g, b);
		return (ERROR_NONE);
	}
	*color = create_trgb(ALPHA_TRANSPARENT, DEFAULT_RED,
			DEFAULT_GREEN, DEFAULT_BLUE);
	return (ERROR_NONE);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << SHIFT_ALPHA | r << SHIFT_RED | g << SHIFT_GREEN | b);
}
