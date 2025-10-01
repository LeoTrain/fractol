/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leberton <leberton@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:36:24 by leberton          #+#    #+#             */
/*   Updated: 2025/09/06 17:38:32 by leberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;
	int		sign;

	c = (char *)str;
	sign = 1;
	if (*c == '-')
	{
		sign = -1;
		c++;
	}
	else if (*c == '+')
		c++;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	res2 = (double)ft_atoi(c);
	if (res2 < 0)
		res2 = -res2;
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	return (sign * (res + res2));
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

	i = 0;
	has_digit = 0;
	if (*str == '-' || *str == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
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
