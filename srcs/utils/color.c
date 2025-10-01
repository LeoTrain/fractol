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
		t = t * t * (3.0 - 2.0 * t);
		r = (int)(255 * pow(t, 0.4));
		g = (int)(255 * pow(t, 0.6));
		b = (int)(255 * t);
		*color = create_trgb(0, r, g, b);
		return (ERROR_NONE);
	}
	*color = create_trgb(0, 10, 5, 25);
	return (ERROR_NONE);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
