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

int	iteration_to_color(int iteration, int iteration_max)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iteration < iteration_max)
	{
		t = (double)iteration / iteration_max;
		r = (int)(255 * (0.5 + 0.5 * sin(t * 6.28)));
		g = (int)(255 * (0.5 + 0.5 * sin(t * 6.28 + 2.09)));
		b = (int)(255 * (0.5 + 0.5 * sin(t * 6.28 + 4.18)));
		return (create_trgb(0, r, g, b));
	}
	return (create_trgb(0, 0, 0, 0));
}

void	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dest = img->address + (y * img->line_length + x
			* (img->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
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
	free(data->mlx.window);
	free(data->mlx.img.image);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
