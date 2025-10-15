/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:11:18 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:11:39 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/time.h>
# include <mlx.h>

# include "../ft_printf/headers/ft_printf.h"

# include "fractol_constants.h"
# include "fractol_types.h"

double		ft_atof(const char *str);
int			ft_strcmp(char *s1, char *s2);
int			is_valid_number(const char *str);

t_errors	show_error(t_errors error);
void		cleanup_mlx(t_data *data);
int			close_all(void *param);

t_errors	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);
t_errors	iteration_to_color(int iteration, int iteration_max, int *color);

t_errors	parse_arguments(int argc, char **argv, t_fractal *fractal);
t_errors	init_minitlibx(t_data *data);
t_errors	pixel_to_complex(int x, int y, t_data *data, t_complex *complex);
int			mandelbrot_iterations(t_complex complex, int iteration_max);
int			julia_iterations(t_complex z, t_complex constant,
				int iteration_max);
int			sierpinski_iterations(t_complex point, int iteration_max);
t_errors	render_fractol(t_data *data);

int			hook_handle_loop(void *param);
int			hook_handle_mouse(int button, int x, int y, void *param);
int			hook_handle_keypress(int keycode, void *param);

#endif
