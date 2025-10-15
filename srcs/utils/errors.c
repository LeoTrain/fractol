/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:14 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:05:19 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_errors	show_usage(void);

t_errors	show_error(t_errors error)
{
	if (error == ERROR_ARGS)
		ft_printf(MSG_ERROR_INVALID_ARGS);
	if (error == ERROR_ARGS_INVALID_NBR)
		ft_printf(MSG_ERROR_INVALID_NBR);
	if (error == ERROR_ARGS_INVALID_AMOUNT)
		ft_printf(MSG_ERROR_INVALID_AMOUNT);
	if (error == ERROR_ARGS_INVALID_FRACTAL)
		ft_printf(MSG_ERROR_INVALID_FRACTAL);
	show_usage();
	return (error);
}

static t_errors	show_usage(void)
{
	ft_printf(MSG_SHOW_USAGE);
	return (ERROR_ARGS);
}
