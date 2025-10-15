/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:05:18 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:05:19 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_errors	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return (ERROR_NONE);
	dest = img->address + (y * img->line_length + x * (
				img->bit_per_pixel / BITS_PER_PIXEL_DIVISOR));
	*(unsigned int *)dest = color;
	return (ERROR_NONE);
}
