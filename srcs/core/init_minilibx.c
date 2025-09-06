/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:31:12 by leberton          #+#    #+#             */
/*   Updated: 2025/09/06 17:31:13 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	init_mlx_img(t_data *data);
static int	handle_keypress(int keycode, void *param);
static int	handle_mouse(int button, int x, int y, void *param);
static int	loop_loop(void *param);

int	init_minitlibx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		return (EXIT_FAILURE);
	data->mlx.window = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "Fractol");
	if (data->mlx.window == NULL)
	{
		mlx_destroy_display(data->mlx.mlx);
		return (EXIT_FAILURE);
	}
	data->size.width = WIDTH;
	data->size.height = HEIGHT;
	init_mlx_img(data);
	mlx_hook(data->mlx.window, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->mlx.window, 17, 0, close_all, data);
	mlx_mouse_hook(data->mlx.window, handle_mouse, data);
	mlx_loop_hook(data->mlx.mlx, loop_loop, data);
	return (EXIT_SUCCESS);
}

static int	init_mlx_img(t_data *data)
{
	data->mlx.img.image = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	if (data->mlx.img.image == NULL)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.window);
		mlx_destroy_display(data->mlx.mlx);
		return (EXIT_FAILURE);
	}
	data->mlx.img.address = mlx_get_data_addr(data->mlx.img.image,
			&data->mlx.img.bit_per_pixel, &data->mlx.img.line_length,
			&data->mlx.img.endian);
	if (data->mlx.img.address == NULL)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.window);
		mlx_destroy_display(data->mlx.mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	loop_loop(void *param)
{
	t_data			*data;

	data = (t_data *)param;
	if (data->needs_redraw == 1)
	{
		render_fractol(data);
		data->needs_redraw = 0;
	}
	return (EXIT_SUCCESS);
}

static int	handle_mouse(int button, int x, int y, void *param)
{
	t_data			*data;
	t_complex		mouse_complex;

	data = (t_data *)param;
	if ((button == 4 || button == 5) && data->needs_redraw == 0)
	{
		mouse_complex = pixel_to_complex(x, y, &data->fractal, &data->size);
		if (button == 4)
			data->fractal.zoom_level *= 1.1;
		else
			data->fractal.zoom_level /= 1.1;
		data->fractal.complex_center = mouse_complex;
		data->needs_redraw = 1;
	}
	return (EXIT_SUCCESS);
}

static int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
		close_all(keycode, data);
	else if (keycode == 65361 || keycode == 65363)
	{
		if (keycode == 65363)
			data->fractal.complex_center.real += 0.1;
		else
			data->fractal.complex_center.real -= 0.1;
		data->needs_redraw = 1;
	}
	else if (keycode == 65362 || keycode == 65364)
	{
		if (keycode == 65362)
			data->fractal.complex_center.imaginary += 0.1;
		else
			data->fractal.complex_center.imaginary -= 0.1;
		data->needs_redraw = 1;
	}
	return (EXIT_SUCCESS);
}
