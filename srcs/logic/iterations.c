/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:35:15 by leberton          #+#    #+#             */
/*   Updated: 2025/09/06 17:35:17 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	mandelbrot_iterations(double c_real, double c_imaginary, int iteration_max)
{
	double	real;
	double	real_new;
	double	imaginary;
	double	imaginary_new;
	int		iteration_current;

	real = 0;
	imaginary = 0;
	iteration_current = 0;
	while (iteration_current < iteration_max
		&& (real * real + imaginary * imaginary) <= 4)
	{
		real_new = real * real - imaginary * imaginary + c_real;
		imaginary_new = 2 * real * imaginary + c_imaginary;
		real = real_new;
		imaginary = imaginary_new;
		iteration_current++;
	}
	return (iteration_current);
}

int	julia_iterations(t_complex z, t_complex constant, int max_iterations)
{
	double	real;
	double	imaginary;
	int		iteration_current;
	double	real_new;
	double	imaginary_new;

	real = z.real;
	imaginary = z.imaginary;
	iteration_current = 0;
	while (iteration_current < max_iterations
		&& (real * real + imaginary * imaginary) <= 4)
	{
		real_new = real * real - imaginary * imaginary + constant.real;
		imaginary_new = 2 * real * imaginary + constant.imaginary;
		real = real_new;
		imaginary = imaginary_new;
		iteration_current++;
	}
	return (iteration_current);
}
