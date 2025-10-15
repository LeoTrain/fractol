/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:36:24 by leberton          #+#    #+#             */
/*   Updated: 2025/10/01 17:05:19 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	get_sign(const char **str);
static void	skip_to_decimal(const char **str);

double	ft_atof(const char *str)
{
	double	integer_part;
	double	decimal_part;
	int		sign;
	int		decimal_length;

	sign = get_sign(&str);
	integer_part = (double)ft_atoi(str);
	skip_to_decimal(&str);
	if (*str == '.')
		str++;
	decimal_part = (double)ft_atoi(str);
	if (decimal_part < 0)
		decimal_part = -decimal_part;
	decimal_length = ft_strlen(str);
	while (decimal_length--)
		decimal_part /= BASE_DECIMAL;
	return (sign * (integer_part + decimal_part));
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = SIGN_PLUS;
	if (**str == '-')
	{
		sign = SIGN_MINUS;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

static void	skip_to_decimal(const char **str)
{
	while (**str && **str != '.')
		(*str)++;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	is_valid_number(const char *str)
{
	int	i;
	int	has_digit;
	int	dot_count;

	i = 0;
	has_digit = 0;
	dot_count = 0;
	if (*str == '-' || *str == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		has_digit = 1;
		i++;
	}
	return (has_digit);
}
