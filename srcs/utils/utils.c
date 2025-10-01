/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:38:16 by leberton          #+#    #+#             */
/*   Updated: 2025/09/06 17:38:18 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	create_trgb(int t, int r, int g, int b);

t_errors	iteration_to_color(int iteration, int iteration_max, int *color)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iteration < iteration_max)
	{
		t = (double)iteration / iteration_max;
		t = t * t * (3.0 - 2.0 * t);
		r = (int)(255 * pow(t, 0.4));
		g = (int)(255 * pow(t, 0.6));
		b = (int)(255 * t);
		*color = create_trgb(0, r, g, b);
		return (ERROR_NONE);
	}
	*color = create_trgb(0, 10, 5, 25);
	return (ERROR_NONE);
}

t_errors	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return (ERROR_NONE);
	dest = img->address + (y * img->line_length + x
			* (img->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
	return (ERROR_NONE);
}

int	close_all(int keycode, void *param)
{
	t_data	*data;

	(void)keycode;
	data = (t_data *)param;
	mlx_destroy_window(data->mlx.mlx, data->mlx.window);
	mlx_destroy_image(data->mlx.mlx, data->mlx.img.image);
	mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
