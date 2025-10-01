/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:37:37 by leberton          #+#    #+#             */
/*   Updated: 2025/09/06 17:37:38 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_errors	show_usage_and_exit(void);
static t_errors	set_mandelbrot(t_fractal *fractal);
static t_errors	set_julia(t_fractal *fractal, double c_real, double c_imaginary);

t_errors	parse_arguments(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
		return (show_usage_and_exit());
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		return (set_mandelbrot(fractal));
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			return (show_usage_and_exit());
		return (set_julia(fractal, ft_atof(argv[2]), ft_atof(argv[3])));
	}
	return (show_usage_and_exit());
}

static t_errors	set_julia(t_fractal *fractal, double c_real, double c_imaginary)
{
	fractal->type = JULIA;
	fractal->complex_center.real = 0;
	fractal->complex_center.imaginary = 0;
	fractal->complex_julia.real = c_real;
	fractal->complex_julia.imaginary = c_imaginary;
	fractal->zoom_level = 1.0;
	fractal->max_iterations = 100;
	return (ERROR_NONE);
}

static t_errors	set_mandelbrot(t_fractal *fractal)
{
	fractal->type = MANDELBROT;
	fractal->complex_center.real = 0;
	fractal->complex_center.imaginary = 0;
	fractal->zoom_level = 1.0;
	fractal->max_iterations = 100;
	return (ERROR_NONE);
}

static t_errors	show_usage_and_exit(void)
{
	printf("Usages:\n");
	printf("./fractol mandelbrot\n");
	printf("./fractol julia <real> <imaginary>\n");
	return (ERROR_ARGS);
}
