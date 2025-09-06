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
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (parse_arguments(argc, argv, &data.fractal) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_minitlibx(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	render_fractol(&data);
	mlx_loop(data.mlx.mlx);
	return (EXIT_SUCCESS);
}
