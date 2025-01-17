/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:50:00 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/17 14:25:14 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../code/fractol.h"

static int	skip_ws_and_s(const char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static double	parse_decimal(const char *str, int *i)
{
	double	decimal;
	double	divisor;

	decimal = 0;
	divisor = 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		decimal = decimal * 10 + (str[*i] - '0');
		divisor *= 10;
		(*i)++;
	}
	return (decimal / divisor);
}

double	ft_atof(const char *str)
{
	int		sign;
	int		i;
	double	result;

	sign = 1;
	i = skip_ws_and_s(str, &sign);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		result += parse_decimal(str, &i);
	}
	return (sign * result);
}
