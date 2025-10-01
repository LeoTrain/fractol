#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#define WIDTH 1080
#define HEIGHT 720

#define BLUE 0x000000FF
#define RED 0x00FF0000
#define BLACK 0x000000

#define ESC_KEY 65307
#define LEFT_KEY 65361
#define UP_KEY 65362
#define RIGHT_KEY 65363
#define DOWN_KEY 65364

typedef enum	e_errors
{
	ERROR_NONE = 0,
	ERROR_MALLOC,
	ERROR_ARGS,
	ERROR_MLX_DISPLAY,
	ERROR_MLX_WINDOW,
	ERROR_MLX_IMG,
	ERROR_MLX_IMG_ADDRESS,
	ERROR_UNKNOWN
}	t_errors;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}	t_fractal_type;

typedef struct s_tile_position
{
	int	x;
	int	y;
}	t_tile_position;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_size
{
	int	width;
	int	height;
}	t_size;

typedef struct s_mlx_img
{
	void	*image;
	char	*address;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
} t_mlx_img;

typedef struct s_mlx_data
{
    void	*mlx;
    void	*window;
    t_mlx_img	img;
}	t_mlx_data;

typedef struct s_fractal
{
    t_fractal_type	type;
    t_complex		complex_center;
    t_complex		complex_julia;
    double		zoom_level;
    int			max_iterations;
}	t_fractal;

typedef struct s_data
{
    t_mlx_data	mlx;
    t_size	size;
    t_fractal	fractal;
    int		needs_redraw;
    long	last_scroll_time;
} t_data;

double	ft_atof(const char *str);
int		ft_strcmp(char *s1, char *s2);

void	cleanup_mlx(t_data *data);
int		close_all(int keycode, void *param);
t_errors	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);
t_errors	iteration_to_color(int iteration, int iteration_max, int *color);

t_errors	parse_arguments(int argc, char **argv, t_fractal *fractal);
t_errors	init_minitlibx(t_data *data);
t_errors	pixel_to_complex(int x, int y, t_data *data, t_complex *complex);
int			mandelbrot_iterations(t_complex complex, int iteration_max);
int		julia_iterations(t_complex z, t_complex constant, int iteration_max);
t_errors	render_fractol(t_data *data);

#endif
