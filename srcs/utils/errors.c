/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:14 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:05:19 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_errors	show_usage(void);

t_errors	show_error(t_errors error)
{
	if (error == ERROR_ARGS)
		ft_printf("Error: Invalid arguments.\n");
	if (error == ERROR_ARGS_INVALID_NBR)
		ft_printf("Error: argument is not a valid number.\n");
	if (error == ERROR_ARGS_INVALID_AMOUNT)
		ft_printf("Error: Invalid arguments amount.\n");
	if (error == ERROR_ARGS_INVALID_FRACTAL)
		ft_printf("Error: Invalid fractal name.\n");
	show_usage();
	return (error);
}

static t_errors	show_usage(void)
{
	ft_printf("Usages:\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol julia <real> <imaginary>\n");
	return (ERROR_ARGS);
}
