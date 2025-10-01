/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:04:54 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:04:55 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	close_all(int keycode, void *param)
{
	t_data	*data;

	(void)keycode;
	data = (t_data *)param;
	cleanup_mlx(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	cleanup_mlx(t_data *data)
{
	if (data->mlx.img.image != NULL)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img.image);
	if (data->mlx.window != NULL)
		mlx_destroy_window(data->mlx.mlx, data->mlx.window);
	if (data->mlx.mlx != NULL)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
	}
}
