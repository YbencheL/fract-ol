/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:42:17 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/11 13:36:54 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mall_err(void)
{
	perror("Memory allocation error\n");
	exit(1);
}

double	map(double unscaled_num, double old_max, double new_min, double new_max)
{
	double	scaled;

	scaled = (unscaled_num - 0) / (old_max - 0) * (new_max - new_min) + new_min;
	return (scaled);
}

void	fract_init(t_vars *fract)
{
	fract->mlx = mlx_init();
	if (fract->mlx == NULL)
		mall_err();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (fract->win == NULL)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		mall_err();
	}
	fract->img.img_p = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (fract->img.img_p == NULL)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
		mall_err();
	}
	fract->img.pix = mlx_get_data_addr(fract->img.img_p, &fract->img.bits,
			&fract->img.l_len, &fract->img.endian);
	data_init(fract);
}
