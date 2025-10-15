/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_constants.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:11:21 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:11:24 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONSTANTS_H
# define FRACTOL_CONSTANTS_H

# define TRUE 1
# define FALSE 0

# define SIGN_PLUS 1
# define SIGN_MINUS -1

# define ITERATION_START 0

# define WIDTH 1080
# define HEIGHT 720

# define ARGC_MIN 2
# define ARGC_JULIA_SET 4

# define STRCMP_OK 0

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define EVENT_KEY_PRESS 2
# define EVENT_DESTROY_NOTIFY 17
# define BITS_PER_PIXEL_DIVISOR 8

# define ZOOM_FACTOR 1.1
# define COORDINATE_CENTER_OFFSET 0.5

# define RGB_MAX_VALUE 255
# define GAMMA_RED 0.4
# define GAMMA_GREEN 0.6
# define SMOOTHING_COEFF_A 3.0
# define SMOOTHING_COEFF_B 2.0
# define ALPHA_TRANSPARENT 0

# define DEFAULT_RED 10
# define DEFAULT_GREEN 5
# define DEFAULT_BLUE 25

# define SHIFT_ALPHA 24
# define SHIFT_RED 16
# define SHIFT_GREEN 8

# define BASE_MOVEMENT_STEP 0.1
# define BASE_SHIFT_X 0
# define BASE_SHIFT_Y 0
# define BASE_DECIMAL 10
# define BASE_COMPLEX_CENTER_REAL 0
# define BASE_COMPLEX_CENTER_IMAGINARY 0
# define BASE_ZOOM_LEVEL 1.0
# define BASE_MAX_ITERATIONS 100
# define BASE_COORD_IMG_X 0
# define BASE_COORD_IMG_Y 0
# define BASE_VIEW_FACTOR 4.0

# define DIVERGENCE_THRESHOLD 4

# define MSG_ERROR_INVALID_ARGS "Error: Invalid arguments.\n"
# define MSG_ERROR_INVALID_NBR "Error: argument is not a valid number.\n"
# define MSG_ERROR_INVALID_AMOUNT "Error: Invalid arguments amount.\n"
# define MSG_ERROR_INVALID_FRACTAL "Error: Invalid fractal name.\n"
# define MSG_SHOW_USAGE "Usages:\n./fractol mandelbrot\n./fractol julia <real> <imaginary>\n"

# define SMOOTHSTEP_COEF_1 3.0
# define SMOOTHSTEP_COEF_2 2.0
# define COLOR_MAX_INTENSITY 255
# define COLOR_EXP_RED 0.4
# define COLOR_EXP_GREEN 0.6
# define NON_DIVERGENT_T 0
# define NON_DIVERGENT_R 10
# define NON_DIVERGENT_G 5
# define NON_DIVERGENT_B 25

# define BITS 8

#endif
