/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:37:37 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:06:53 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#include <unistd.h>

static t_errors	check_julia_validity(int argc, char **argv);
static t_errors	set_mandelbrot(t_fractal *fractal);
static t_errors	set_julia(t_fractal *fractal, double c_real,
					double c_imaginary);
static t_errors	check_for_fractal(int argc, char **argv, t_fractal *fractal);

t_errors	parse_arguments(int argc, char **argv, t_fractal *fractal)
{
	t_errors	error;

	if (argc < ARGC_MIN)
		return (ERROR_ARGS_INVALID_AMOUNT);
	error = check_for_fractal(argc, argv, fractal);
	if (error != ERROR_NONE)
		return (error);
	return (error);
}

static t_errors	check_for_fractal(int argc, char **argv, t_fractal *fractal)
{
	t_errors	error;

	if (ft_strcmp(argv[1], "mandelbrot") == STRCMP_OK)
	{
		if (argc != ARGC_MANDELBROT_SET)
			return (ERROR_ARGS_INVALID_AMOUNT);
		return (set_mandelbrot(fractal));
	}
	else if (ft_strcmp(argv[1], "julia") == STRCMP_OK)
	{
		error = check_julia_validity(argc, argv);
		if (error != ERROR_NONE)
			return (error);
		return (set_julia(fractal, ft_atof(argv[2]), ft_atof(argv[3])));
	}
	return (ERROR_ARGS_INVALID_FRACTAL);
}

static t_errors	set_mandelbrot(t_fractal *fractal)
{
	fractal->type = MANDELBROT;
	fractal->complex_center.real = BASE_COMPLEX_CENTER_REAL;
	fractal->complex_center.imaginary = BASE_COMPLEX_CENTER_IMAGINARY;
	fractal->zoom_level = BASE_ZOOM_LEVEL;
	fractal->max_iterations = BASE_MAX_ITERATIONS;
	return (ERROR_NONE);
}

static t_errors	check_julia_validity(int argc, char **argv)
{
	if (argc != ARGC_JULIA_SET)
		return (ERROR_ARGS_INVALID_AMOUNT);
	if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
		return (ERROR_ARGS_INVALID_NBR);
	return (ERROR_NONE);
}

static t_errors	set_julia(t_fractal *fractal, double c_real, double c_imaginary)
{
	fractal->type = JULIA;
	fractal->complex_center.real = BASE_COMPLEX_CENTER_REAL;
	fractal->complex_center.imaginary = BASE_COMPLEX_CENTER_IMAGINARY;
	fractal->complex_julia.real = c_real;
	fractal->complex_julia.imaginary = c_imaginary;
	fractal->zoom_level = BASE_ZOOM_LEVEL;
	fractal->max_iterations = BASE_MAX_ITERATIONS;
	return (ERROR_NONE);
}
