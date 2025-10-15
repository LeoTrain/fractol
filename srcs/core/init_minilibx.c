/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:31:12 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:04:02 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_errors	init_mlx_img(t_data *data);
static t_errors	init_mlx_hooks(t_data *data);
static t_errors	init_data(t_data *data);

t_errors	init_minitlibx(t_data *data)
{
	t_errors	error;

	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		return (ERROR_MLX_DISPLAY);
	data->mlx.window = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "Fractol");
	if (data->mlx.window == NULL)
	{
		mlx_destroy_display(data->mlx.mlx);
		return (ERROR_MLX_WINDOW);
	}
	error = init_mlx_img(data);
	if (error != ERROR_NONE)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.window);
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		return (error);
	}
	error = init_mlx_hooks(data);
	if (error != ERROR_NONE)
		return (error);
	init_data(data);
	return (ERROR_NONE);
}

static t_errors	init_data(t_data *data)
{
	data->size.width = WIDTH;
	data->size.height = HEIGHT;
	data->shift.x = BASE_SHIFT_X;
	data->shift.y = BASE_SHIFT_Y;
	return (ERROR_NONE);
}

static t_errors	init_mlx_img(t_data *data)
{
	data->mlx.img.image = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	if (data->mlx.img.image == NULL)
		return (ERROR_MLX_IMG);
	data->mlx.img.address = mlx_get_data_addr(data->mlx.img.image,
			&data->mlx.img.bit_per_pixel, &data->mlx.img.line_length,
			&data->mlx.img.endian);
	if (data->mlx.img.address == NULL)
	{
		mlx_destroy_image(data->mlx.mlx, data->mlx.img.image);
		return (ERROR_MLX_IMG_ADDRESS);
	}
	return (ERROR_NONE);
}

static t_errors	init_mlx_hooks(t_data *data)
{
	mlx_hook(data->mlx.window, EVENT_KEY_PRESS, 1L << 0,
		hook_handle_keypress, data);
	mlx_hook(data->mlx.window, EVENT_DESTROY_NOTIFY, 0,
		close_all, data);
	mlx_mouse_hook(data->mlx.window,
		hook_handle_mouse, data);
	mlx_loop_hook(data->mlx.mlx, hook_handle_loop, data);
	return (ERROR_NONE);
}
