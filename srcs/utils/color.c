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
		t = t * t * (SMOOTHSTEP_COEF_1 - SMOOTHSTEP_COEF_2 * t);
		r = (int)(COLOR_MAX_INTENSITY * pow(t, COLOR_EXP_RED));
		g = (int)(COLOR_MAX_INTENSITY * pow(t, COLOR_EXP_GREEN));
		b = (int)(COLOR_MAX_INTENSITY * t);
		*color = create_trgb(0, r, g, b);
		return (ERROR_NONE);
	}
	*color = create_trgb(NON_DIVERGENT_T, NON_DIVERGENT_R, NON_DIVERGENT_G,
					  NON_DIVERGENT_B);
	return (ERROR_NONE);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
