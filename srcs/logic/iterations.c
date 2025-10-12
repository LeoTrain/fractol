/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:35:15 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:07:10 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	has_not_diverged(double real, double imaginary,
				int iteration_current, int iteration_max);

int	mandelbrot_iterations(t_complex complex, int iteration_max)
{
	double	real;
	double	real_new;
	double	imaginary;
	double	imaginary_new;
	int		iteration_current;

	real = 0;
	imaginary = 0;
	iteration_current = 0;
	while (has_not_diverged(real, imaginary, iteration_current, iteration_max))
	{
		real_new = real * real - imaginary * imaginary + complex.real;
		imaginary_new = 2 * real * imaginary + complex.imaginary;
		real = real_new;
		imaginary = imaginary_new;
		iteration_current++;
	}
	return (iteration_current);
}

int	julia_iterations(t_complex z, t_complex constant, int iteration_max)
{
	double	real;
	double	imaginary;
	int		iteration_current;
	double	real_new;
	double	imaginary_new;

	real = z.real;
	imaginary = z.imaginary;
	iteration_current = 0;
	while (has_not_diverged(real, imaginary, iteration_current, iteration_max))
	{
		real_new = real * real - imaginary * imaginary + constant.real;
		imaginary_new = 2 * real * imaginary + constant.imaginary;
		real = real_new;
		imaginary = imaginary_new;
		iteration_current++;
	}
	return (iteration_current);
}

int			sierpinski_iterations(t_complex point, int iteration_max)
{
	double	x;
	double	y;
	int		i;
	int		count;

	x = (point.real + 2.0) * 0.5;
	y = (point.imaginary + 2.0) * 0.5;

	count = 0;
	i = 0;
	while (i < iteration_max)
	{
		if (x < 0.5)
		{
			x = 2.0 * x;
			y = 2.0 * y;
		}
		else if (y < 0.5)
		{
			x = 2.0 * x - 1.0;
			y = 2.0 * y;
		}
		else
		{
			x = 2.0 * x - 1.0;
			y = 2.0 * y - 1.0;
		}
		if (x >= 0.0 && x <= 1.0 && y >= 0.0 && y <= 1.0)
			count++;
		i++;
	}
	return (count);
}

static int	has_not_diverged(double real, double imaginary,
							int iteration_current, int iteration_max)
{
	return (iteration_current < iteration_max
		&& (real * real + imaginary * imaginary) <= 4);
}
