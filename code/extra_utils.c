/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:36:25 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/17 09:47:35 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comx	sum_comx(t_comx z1, t_comx z2)
{
	t_comx	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_comx	square_comx(t_comx z)
{
	t_comx	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_comx	abs_comx(t_comx z)
{
	t_comx	result;

	result.x = fabs(z.x);
	result.y = fabs(z.y);
	return (result);
}
