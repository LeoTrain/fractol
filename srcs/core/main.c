/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:30:58 by leberton          #+#    #+#             */
/*   Updated: 2025/09/06 17:30:59 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_errors	error;
	t_data		data;

	ft_memset(&data, 0, sizeof(t_data));
	error = parse_arguments(argc, argv, &data.fractal);
	if (error != ERROR_NONE)
		return (error);
	error = init_minitlibx(&data);
	if (error != ERROR_NONE)
		return (error);
	error = render_fractol(&data);
	if (error != ERROR_NONE)
		return (error);
	mlx_loop(data.mlx.mlx);
	return (EXIT_SUCCESS);
}
