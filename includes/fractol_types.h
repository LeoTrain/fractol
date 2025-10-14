/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:11:23 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:15:57 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_TYPES_H
# define FRACTOL_TYPES_H

typedef enum e_errors
{
	ERROR_NONE = 0,
	ERROR_MALLOC,
	ERROR_ARGS,
	ERROR_ARGS_INVALID_NBR,
	ERROR_ARGS_INVALID_AMOUNT,
	ERROR_ARGS_INVALID_FRACTAL,
	ERROR_MLX_DISPLAY,
	ERROR_MLX_WINDOW,
	ERROR_MLX_IMG,
	ERROR_MLX_IMG_ADDRESS,
	ERROR_UNKNOWN
}	t_errors;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
}	t_fractal_type;

typedef struct s_tile_position
{
	int				x;
	int				y;
}					t_tile_position;

typedef struct s_complex
{
	double			real;
	double			imaginary;
}					t_complex;

typedef struct s_size
{
	int				width;
	int				height;
}					t_size;

typedef struct s_mlx_img
{
	void			*image;
	char			*address;
	int				bit_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx_img;

typedef struct s_mlx_data
{
	void			*mlx;
	void			*window;
	t_mlx_img		img;
}					t_mlx_data;

typedef struct s_fractal
{
	t_fractal_type	type;
	t_complex		complex_center;
	t_complex		complex_julia;
	double			zoom_level;
	int				max_iterations;
}					t_fractal;

typedef struct s_data
{
	t_mlx_data		mlx;
	t_size			size;
	t_fractal		fractal;
	int				needs_redraw;
	long			last_scroll_time;
}					t_data;

#endif
