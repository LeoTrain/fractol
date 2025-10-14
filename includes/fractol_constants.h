/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_constants.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:11:21 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:11:24 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_CONSTANTS_H
# define FRACTOL_CONSTANTS_H

# define WIDTH 1080
# define HEIGHT 720

# define MINARGC 2
# define ARGCJULIA 4

# define IMGSTARTX 0
# define IMGSTARTY 0

# define BLUE 0x000000FF
# define RED 0x00FF0000
# define BLACK 0x000000

# define ESC_KEY 65307
# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364

# define NEEDSREDRAW 1
# define NEEDSNOTREDRAW 0

# define SCROLLUPKEY 4
# define SCROLLDOWNKEY 5

# define KEYPRESSEVENT 2
# define DESTROYNOTIFYEVENT 17

# define NOEVENTMASK 0
# define KEYPRESSMASK 1L<<0

# define ITERATIONSTART 0

# define MAXDIVERGENCE 4

# define REALSTART 0
# define IMAGINARYSTART 0
# define ZOOMSTART 1.0
# define MAXITERATIONS 100

# define SMOOTHSTEP_COEF_1 3.0
# define SMOOTHSTEP_COEF_2 2.0
# define COLOR_MAX_INTENSITY 255
# define COLOR_EXP_RED 0.4
# define COLOR_EXP_GREEN 0.6
# define NON_DIVERGENT_T 0
# define NON_DIVERGENT_R 10
# define NON_DIVERGENT_G 5
# define NON_DIVERGENT_B 25

# define BITS 8

#endif
